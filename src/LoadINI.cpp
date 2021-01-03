#include "LoadINI.hpp"
#include <iostream>
#include <unordered_map>
#include <string>
#include <cstring>
#include <confini.h>


static inline void chrarr_tolower (char * const str) {
    for (register char * chrptr = str; *chrptr; chrptr++) {
        *chrptr = *chrptr > 0x40 && *chrptr < 0x5b ? *chrptr | 0x60 : *chrptr;
    }
}

/*

In this implementation the dot is a metacharacter and is used as delimiter
between path parts. Therefore all dots appearing in key names, or (within
quotes) in section paths, will be replaced with the following character. You
may change it with any other character (except the dot itself).

*/
#define DOT_REPLACEMENT '-'


/*  Parse a path pointing to an INI file  */
int IniLoadMap::mapPath (const std::string path, const IniFormat format, const IniDispHandler callback) {
    this->dictionary.clear();
    this->_format_ = format;
    return load_ini_path(path.c_str(), format, NULL, callback, &dictionary);
}

/*  Get the INI source string of a value  */
std::string IniLoadMap::getSource (const std::string key) {
    if (!dictionary.count(key)) {
        /*  You can change this to `return ""` if you prefer...  */
        throw std::runtime_error("Key not present.");
    }
    return dictionary.at(key);
}


/*  Get a value parsed as a std::string  */
std::string IniLoadMap::getString (const std::string key) {
    const std::string srcstr = this->getSource(key);
    size_t len = srcstr.length();
    char * tmp = new char[len + 1];
    memcpy(tmp, srcstr.c_str(), len + 1);
    len = ini_string_parse(tmp, this->_format_);
    std::string myString(tmp, len);
    delete tmp;
    return myString;
}

/*  Private `IniDispHandler`  */
int IniLoadMap::_push_dispatch_ (IniDispatch * const disp, void * const v_dictionary) {

#define thismap (reinterpret_cast<std::unordered_map<std::string, std::string> *>(v_dictionary))

    if (disp->type != INI_KEY) {

        return 0;

    }

    size_t idx;
    char * newptr1, * newptr2, * oldptr1, * oldptr2;
    disp->d_len = ini_unquote(disp->data, disp->format);

    /*  remove quoted dots from parent  */
    if (disp->at_len) {

        /*  has parent  */
        newptr1 = newptr2 = new char[disp->at_len + 1];
        *((const char **) &oldptr2) = disp->append_to;

        while ((oldptr1 = oldptr2)) {

            idx = ini_array_shift((const char **) &oldptr2, '.', disp->format);
            newptr1[idx] = '\0';

            while (idx > 0) {

                --idx;
                newptr1[idx] = oldptr1[idx] == '.' ? DOT_REPLACEMENT : oldptr1[idx];

            }

            newptr1 += ini_unquote(newptr1, disp->format);
            *newptr1++ = '.';

        }

        idx = newptr1 - newptr2;
        newptr1 = new char[idx + disp->d_len + 1];
        memcpy(newptr1, newptr2, idx);
        delete newptr2;
        newptr2 = newptr1 + idx;

    } else {

        /*  parent is root  */
        newptr1 = newptr2 = new char[disp->d_len + 1];

    }

    /*  remove dots from key name  */
    idx = disp->d_len + 1;

    do {

        --idx;
        newptr2[idx] = disp->data[idx] == '.' ? DOT_REPLACEMENT : disp->data[idx];

    } while (idx > 0);

    if (!disp->format.case_sensitive) {

        chrarr_tolower(newptr1);

    }

    std::string key = std::string(newptr1, newptr2 - newptr1 + disp->d_len);
    delete newptr1;

    /*  check for duplicate keys  */
    if (thismap->count(key)) {

        std::cerr << "`" << key << "` will be overwritten (duplicate key found)\n";
        thismap->erase(key);

    }

    thismap->insert(
            std::pair<std::string, std::string>(
                    key,
                    disp->value ? std::string(disp->value, disp->v_len) : ""
            )
    );

    return 0;

#undef thismap
}
