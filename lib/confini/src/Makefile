# Makefile.in generated by automake 1.15.1 from Makefile.am.
# src/Makefile.  Generated from Makefile.in by configure.

# Copyright (C) 1994-2017 Free Software Foundation, Inc.

# This Makefile.in is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY, to the extent permitted by law; without
# even the implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE.



###############################################################################
###############################################################################

# NOTE:  Upper case variables may be freely overridden by the user, while lower
#        case variables, especially those beginning with an underscore, are for
#        internal use only.




am__is_gnu_make = { \
  if test -z '$(MAKELEVEL)'; then \
    false; \
  elif test -n '$(MAKE_HOST)'; then \
    true; \
  elif test -n '$(MAKE_VERSION)' && test -n '$(CURDIR)'; then \
    true; \
  else \
    false; \
  fi; \
}
am__make_running_with_option = \
  case $${target_option-} in \
      ?) ;; \
      *) echo "am__make_running_with_option: internal error: invalid" \
              "target option '$${target_option-}' specified" >&2; \
         exit 1;; \
  esac; \
  has_opt=no; \
  sane_makeflags=$$MAKEFLAGS; \
  if $(am__is_gnu_make); then \
    sane_makeflags=$$MFLAGS; \
  else \
    case $$MAKEFLAGS in \
      *\\[\ \	]*) \
        bs=\\; \
        sane_makeflags=`printf '%s\n' "$$MAKEFLAGS" \
          | sed "s/$$bs$$bs[$$bs $$bs	]*//g"`;; \
    esac; \
  fi; \
  skip_next=no; \
  strip_trailopt () \
  { \
    flg=`printf '%s\n' "$$flg" | sed "s/$$1.*$$//"`; \
  }; \
  for flg in $$sane_makeflags; do \
    test $$skip_next = yes && { skip_next=no; continue; }; \
    case $$flg in \
      *=*|--*) continue;; \
        -*I) strip_trailopt 'I'; skip_next=yes;; \
      -*I?*) strip_trailopt 'I';; \
        -*O) strip_trailopt 'O'; skip_next=yes;; \
      -*O?*) strip_trailopt 'O';; \
        -*l) strip_trailopt 'l'; skip_next=yes;; \
      -*l?*) strip_trailopt 'l';; \
      -[dEDm]) skip_next=yes;; \
      -[JT]) skip_next=yes;; \
    esac; \
    case $$flg in \
      *$$target_option*) has_opt=yes; break;; \
    esac; \
  done; \
  test $$has_opt = yes
am__make_dryrun = (target_option=n; $(am__make_running_with_option))
am__make_keepgoing = (target_option=k; $(am__make_running_with_option))
pkgdatadir = $(datadir)/libconfini
pkgincludedir = $(includedir)/libconfini
pkglibdir = $(libdir)/libconfini
pkglibexecdir = $(libexecdir)/libconfini
am__cd = CDPATH="$${ZSH_VERSION+.}$(PATH_SEPARATOR)" && cd
install_sh_DATA = $(install_sh) -c -m 644
install_sh_PROGRAM = $(install_sh) -c
install_sh_SCRIPT = $(install_sh) -c
INSTALL_HEADER = $(INSTALL_DATA)
transform = $(program_transform_name)
NORMAL_INSTALL = :
PRE_INSTALL = :
POST_INSTALL = :
NORMAL_UNINSTALL = :
PRE_UNINSTALL = :
POST_UNINSTALL = :
build_triplet = x86_64-pc-linux-gnu
host_triplet = x86_64-pc-linux-gnu
#am__append_1 = \
#	confini-baremetal.h \
#	confini-baremetal.c

am__append_2 = \
	confini.h \
	confini.c

#am__append_3 = \
#	-no-undefined

##am__append_4 = \
##	-export-dynamic

##am__append_5 = \
##	winres-ac.rc

#am__append_6 = \
#	-avoid-version


# Create `$(PROJECT_CONFNAME).h` only when the package must *not* coexist with
# other major versions of itself
am__append_7 = \
	(cd '$(DESTDIR)$(includedir)' && \
	$(LN_S) 'confini-1.16.h' \
	'confini.h');


# Create `$(PROJECT_CONFNAME)-$(PROJECT_EFFVER).h` and
# `$(PROJECT_CONFNAME)-$(PROJECT_MAJVER).h`
am__append_8 = \
	$(_headers_insthook_)

am__append_9 = \
	$(UNINSTALLHEADERSFILES)

#am__append_10 = \
#	confini.def \
#	confini.exp \
#	confini-baremetal.def \
#	confini-baremetal.exp

subdir = src
ACLOCAL_M4 = $(top_srcdir)/aclocal.m4
am__aclocal_m4_deps = $(top_srcdir)/m4/libtool.m4 \
	$(top_srcdir)/m4/ltoptions.m4 $(top_srcdir)/m4/ltsugar.m4 \
	$(top_srcdir)/m4/ltversion.m4 $(top_srcdir)/m4/lt~obsolete.m4 \
	$(top_srcdir)/autostuff/m4/not-autotools.m4 \
	$(top_srcdir)/configure.ac
am__configure_deps = $(am__aclocal_m4_deps) $(CONFIGURE_DEPENDENCIES) \
	$(ACLOCAL_M4)
DIST_COMMON = $(srcdir)/Makefile.am $(am__include_HEADERS_DIST) \
	$(am__DIST_COMMON)
mkinstalldirs = $(install_sh) -d
CONFIG_CLEAN_FILES = winres-ac.rc ${PACKAGE_LOCALNAME}.pc
CONFIG_CLEAN_VPATH_FILES =
am__vpath_adj_setup = srcdirstrip=`echo "$(srcdir)" | sed 's|.|.|g'`;
am__vpath_adj = case $$p in \
    $(srcdir)/*) f=`echo "$$p" | sed "s|^$$srcdirstrip/||"`;; \
    *) f=$$p;; \
  esac;
am__strip_dir = f=`echo $$p | sed -e 's|^.*/||'`;
am__install_max = 40
am__nobase_strip_setup = \
  srcdirstrip=`echo "$(srcdir)" | sed 's/[].[^$$\\*|]/\\\\&/g'`
am__nobase_strip = \
  for p in $$list; do echo "$$p"; done | sed -e "s|$$srcdirstrip/||"
am__nobase_list = $(am__nobase_strip_setup); \
  for p in $$list; do echo "$$p $$p"; done | \
  sed "s| $$srcdirstrip/| |;"' / .*\//!s/ .*/ ./; s,\( .*\)/[^/]*$$,\1,' | \
  $(AWK) 'BEGIN { files["."] = "" } { files[$$2] = files[$$2] " " $$1; \
    if (++n[$$2] == $(am__install_max)) \
      { print $$2, files[$$2]; n[$$2] = 0; files[$$2] = "" } } \
    END { for (dir in files) print dir, files[dir] }'
am__base_list = \
  sed '$$!N;$$!N;$$!N;$$!N;$$!N;$$!N;$$!N;s/\n/ /g' | \
  sed '$$!N;$$!N;$$!N;$$!N;s/\n/ /g'
am__uninstall_files_from_dir = { \
  test -z "$$files" \
    || { test ! -d "$$dir" && test ! -f "$$dir" && test ! -r "$$dir"; } \
    || { echo " ( cd '$$dir' && rm -f" $$files ")"; \
         $(am__cd) "$$dir" && rm -f $$files; }; \
  }
am__installdirs = "$(DESTDIR)$(libdir)" "$(DESTDIR)$(pkgconfigdir)" \
	"$(DESTDIR)$(includedir)" "$(DESTDIR)$(includedir)"
LTLIBRARIES = $(lib_LTLIBRARIES)
libconfini_la_DEPENDENCIES =
am__libconfini_la_SOURCES_DIST = confini.h confini.c
am__objects_1 = confini.lo
am_libconfini_la_OBJECTS = $(am__objects_1)
#am__objects_2 = confini-baremetal.lo
##am__objects_3 = winres-ac.lo
nodist_libconfini_la_OBJECTS = $(am__objects_2) \
	$(am__objects_3)
libconfini_la_OBJECTS =  \
	$(am_libconfini_la_OBJECTS) \
	$(nodist_libconfini_la_OBJECTS)
AM_V_lt = $(am__v_lt_$(V))
am__v_lt_ = $(am__v_lt_$(AM_DEFAULT_VERBOSITY))
am__v_lt_0 = --silent
am__v_lt_1 = 
libconfini_la_LINK = $(LIBTOOL) $(AM_V_lt) --tag=CC \
	$(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=link $(CCLD) \
	$(AM_CFLAGS) $(CFLAGS) $(libconfini_la_LDFLAGS) \
	$(LDFLAGS) -o $@
AM_V_P = $(am__v_P_$(V))
am__v_P_ = $(am__v_P_$(AM_DEFAULT_VERBOSITY))
am__v_P_0 = false
am__v_P_1 = :
AM_V_GEN = $(am__v_GEN_$(V))
am__v_GEN_ = $(am__v_GEN_$(AM_DEFAULT_VERBOSITY))
am__v_GEN_0 = @echo "  GEN     " $@;
am__v_GEN_1 = 
AM_V_at = $(am__v_at_$(V))
am__v_at_ = $(am__v_at_$(AM_DEFAULT_VERBOSITY))
am__v_at_0 = @
am__v_at_1 = 
DEFAULT_INCLUDES = -I.
depcomp = $(SHELL) $(top_srcdir)/build-aux/depcomp
am__depfiles_maybe = depfiles
am__mv = mv -f
COMPILE = $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) \
	$(CPPFLAGS) $(AM_CFLAGS) $(CFLAGS)
LTCOMPILE = $(LIBTOOL) $(AM_V_lt) --tag=CC $(AM_LIBTOOLFLAGS) \
	$(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) \
	$(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) \
	$(AM_CFLAGS) $(CFLAGS)
AM_V_CC = $(am__v_CC_$(V))
am__v_CC_ = $(am__v_CC_$(AM_DEFAULT_VERBOSITY))
am__v_CC_0 = @echo "  CC      " $@;
am__v_CC_1 = 
CCLD = $(CC)
LINK = $(LIBTOOL) $(AM_V_lt) --tag=CC $(AM_LIBTOOLFLAGS) \
	$(LIBTOOLFLAGS) --mode=link $(CCLD) $(AM_CFLAGS) $(CFLAGS) \
	$(AM_LDFLAGS) $(LDFLAGS) -o $@
AM_V_CCLD = $(am__v_CCLD_$(V))
am__v_CCLD_ = $(am__v_CCLD_$(AM_DEFAULT_VERBOSITY))
am__v_CCLD_0 = @echo "  CCLD    " $@;
am__v_CCLD_1 = 
SOURCES = $(libconfini_la_SOURCES) \
	$(nodist_libconfini_la_SOURCES)
DIST_SOURCES = $(am__libconfini_la_SOURCES_DIST)
am__can_run_installinfo = \
  case $$AM_UPDATE_INFO_DIR in \
    n|no|NO) false;; \
    *) (install-info --version) >/dev/null 2>&1;; \
  esac
DATA = $(nodist_noinst_DATA) $(pkgconfig_DATA)
am__include_HEADERS_DIST = confini.h
HEADERS = $(include_HEADERS) $(nodist_include_HEADERS)
am__tagged_files = $(HEADERS) $(SOURCES) $(TAGS_FILES) $(LISP)
# Read a list of newline-separated strings from the standard input,
# and print each of them once, without duplicates.  Input order is
# *not* preserved.
am__uniquify_input = $(AWK) '\
  BEGIN { nonempty = 0; } \
  { items[$$0] = 1; nonempty = 1; } \
  END { if (nonempty) { for (i in items) print i; }; } \
'
# Make sure the list of sources is unique.  This is necessary because,
# e.g., the same source file might be shared among _SOURCES variables
# for different programs/libraries.
am__define_uniq_tagged_files = \
  list='$(am__tagged_files)'; \
  unique=`for i in $$list; do \
    if test -f "$$i"; then echo $$i; else echo $(srcdir)/$$i; fi; \
  done | $(am__uniquify_input)`
ETAGS = etags
CTAGS = ctags
am__DIST_COMMON = $(srcdir)/Makefile.in $(srcdir)/libconfini.pc.in \
	$(top_srcdir)/autostuff/shadows/src/winres-ac.rc.in \
	$(top_srcdir)/build-aux/depcomp
DISTFILES = $(DIST_COMMON) $(DIST_SOURCES) $(TEXINFOS) $(EXTRA_DIST)
ACLOCAL = ${SHELL} /home/laurine/Documents/IMAC2/OpenGL/IMAC-OpenGL-3D/lib/confini/build-aux/missing aclocal-1.15
AMTAR = $${TAR-tar}
AM_DEFAULT_VERBOSITY = 0
AR = ar
AS = as
AUTOCONF = ${SHELL} /home/laurine/Documents/IMAC2/OpenGL/IMAC-OpenGL-3D/lib/confini/build-aux/missing autoconf
AUTOHEADER = ${SHELL} /home/laurine/Documents/IMAC2/OpenGL/IMAC-OpenGL-3D/lib/confini/build-aux/missing autoheader
AUTOMAKE = ${SHELL} /home/laurine/Documents/IMAC2/OpenGL/IMAC-OpenGL-3D/lib/confini/build-aux/missing automake-1.15
AWK = mawk
CC = gcc
CCDEPMODE = depmode=gcc3
CFLAGS = 
CPP = gcc -E
CPPFLAGS = 
CYGPATH_W = echo
DEFS = -DPACKAGE_NAME=\"libconfini\" -DPACKAGE_TARNAME=\"libconfini\" -DPACKAGE_VERSION=\"1.16.0\" -DPACKAGE_STRING=\"libconfini\ 1.16.0\" -DPACKAGE_BUGREPORT=\"madmurphy333@gmail.com\" -DPACKAGE_URL=\"https://madmurphy.github.io/libconfini\" -DPACKAGE=\"libconfini\" -DVERSION=\"1.16.0\" -DSTDC_HEADERS=1 -DHAVE_SYS_TYPES_H=1 -DHAVE_SYS_STAT_H=1 -DHAVE_STDLIB_H=1 -DHAVE_STRING_H=1 -DHAVE_MEMORY_H=1 -DHAVE_STRINGS_H=1 -DHAVE_INTTYPES_H=1 -DHAVE_STDINT_H=1 -DHAVE_UNISTD_H=1 -DHAVE__BOOL=1 -DHAVE_STDBOOL_H=1 -DHAVE_STDDEF_H=1 -DHAVE_STDINT_H=1 -DHAVE_STDIO_H=1 -DHAVE_STDLIB_H=1 -DHAVE_STDLIB_H=1 -DHAVE_MALLOC=1 -DHAVE_DLFCN_H=1 -DLT_OBJDIR=\".libs/\"
DEPDIR = .deps
DLLTOOL = false
DSYMUTIL = 
DUMPBIN = 
ECHO_C = 
ECHO_N = -n
ECHO_T = 
EGREP = /bin/grep -E
EXEEXT = 
FGREP = /bin/grep -F
FIND = /usr/bin/find
GIT_HTTP_SERVER = https://github.com
GREP = /bin/grep
IMPLEMENTATION_NUM = 0
INSTALL = /usr/bin/install -c
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_PROGRAM = ${INSTALL}
INSTALL_SCRIPT = ${INSTALL}
INSTALL_STRIP_PROGRAM = $(install_sh) -c -s
INTERFACES_SUPPORTED = 5
INTERFACE_NUM = 5
LD = /usr/bin/ld -m elf_x86_64
LDFLAGS = 
LIBOBJS = 
LIBRARY_BINVERSION = 0.5.0
LIBS = 
LIBTOOL = $(SHELL) $(top_builddir)/libtool
LICENSE_SPDX = GPL-3.0-or-later
LICENSE_STRING = GNU General Public License, version 3 or any later version
LIPO = 
LN_S = ln -s
LTLIBOBJS = 
LT_SYS_LIBRARY_PATH = 
MAINT = 
MAKEINFO = ${SHELL} /home/laurine/Documents/IMAC2/OpenGL/IMAC-OpenGL-3D/lib/confini/build-aux/missing makeinfo
MAN3PAGES = 
MANIFEST_TOOL = :
MKDIR_P = /bin/mkdir -p
NM = /usr/bin/nm -B
NMEDIT = 
OBJDUMP = objdump
OBJEXT = o
OTOOL = 
OTOOL64 = 
PACKAGE = libconfini
PACKAGE_BUGREPORT = madmurphy333@gmail.com
PACKAGE_CONFNAME = libconfini
PACKAGE_LOCALNAME = libconfini
PACKAGE_NAME = libconfini
PACKAGE_STRING = libconfini 1.16.0
PACKAGE_TARNAME = libconfini
PACKAGE_URL = https://madmurphy.github.io/libconfini
PACKAGE_VERSION = 1.16.0
PATH_SEPARATOR = :
PROJECT_CONFNAME = confini
PROJECT_DESCRIPTION = Yet another INI parser
PROJECT_EFFVER = 1.16
PROJECT_LOCALNAME = confini
PROJECT_MAJVER = 1
PROJECT_MINVER = 16
PROJECT_NAME = confini
PROJECT_REVVER = 0
PUBLISHER_ID = madmurphy
PUBLISHER_NAME = Stefano Gioffré
RANLIB = ranlib
RC = 
RCFLAGS = 
SED = /bin/sed
SET_MAKE = 
SHELL = /bin/bash
STRIP = strip
TESTSONLY_CPPFLAGS = 
TESTS_PRINTF_FUNCTION = 
TESTS_PRINTF_HEADER = 
VERSION = 1.16.0
abs_builddir = /home/laurine/Documents/IMAC2/OpenGL/IMAC-OpenGL-3D/lib/confini/src
abs_srcdir = /home/laurine/Documents/IMAC2/OpenGL/IMAC-OpenGL-3D/lib/confini/src
abs_top_builddir = /home/laurine/Documents/IMAC2/OpenGL/IMAC-OpenGL-3D/lib/confini
abs_top_srcdir = /home/laurine/Documents/IMAC2/OpenGL/IMAC-OpenGL-3D/lib/confini
ac_ct_AR = ar
ac_ct_CC = gcc
ac_ct_DUMPBIN = 
am__include = include
am__leading_dot = .
am__quote = 
am__tar = $${TAR-tar} chof - "$$tardir"
am__untar = $${TAR-tar} xf -
bindir = ${exec_prefix}/bin
build = x86_64-pc-linux-gnu
build_alias = 
build_cpu = x86_64
build_os = linux-gnu
build_vendor = pc
builddir = .
confnewdir = confnew
datadir = ${datarootdir}
datarootdir = ${prefix}/share
default_optimization = 2
docdir = /home/laurine/Documents/IMAC2/OpenGL/IMAC-OpenGL-3D/lib/confini/etc
dvidir = ${docdir}
exec_prefix = ${prefix}
host = x86_64-pc-linux-gnu
host_alias = 
host_cpu = x86_64
host_cpu_pretty = x86-64
host_os = linux-gnu
host_vendor = pc
htmldir = ${docdir}
includedir = /home/laurine/Documents/IMAC2/OpenGL/IMAC-OpenGL-3D/lib/confini/../../include
infodir = ${datarootdir}/info
install_sh = ${SHELL} /home/laurine/Documents/IMAC2/OpenGL/IMAC-OpenGL-3D/lib/confini/build-aux/install-sh
libdir = /home/laurine/Documents/IMAC2/OpenGL/IMAC-OpenGL-3D/lib/confini
libexecdir = ${exec_prefix}/libexec
library_headername = confini
localedir = ${datarootdir}/locale
localstatedir = ${prefix}/var
lt_cv_objdir = .libs
mandir = ${datarootdir}/man
mkdir_p = $(MKDIR_P)
nonportfile = non-portable.h
oldincludedir = /usr/include
pdfdir = ${docdir}
pkgconfigdir = $(libdir)/pkgconfig
prefix = /usr/local
program_transform_name = s,x,x,
psdir = ${docdir}
runstatedir = ${localstatedir}/run
rvdir = REVISEME
sbindir = ${exec_prefix}/sbin
sharedstatedir = ${prefix}/com
srcdir = .
sysconfdir = ${prefix}/etc
target_alias = 
top_build_prefix = ../
top_builddir = ..
top_srcdir = ..
LTVERSIONINFO = $(INTERFACE_NUM):$(IMPLEMENTATION_NUM):$(INTERFACES_SUPPORTED)
_common_cppenv_ = \
	"-DPACKAGE_LOCALE_DIR=\"$(localedir)\"" \
	"-DPACKAGE_SRC_DIR=\"$(srcdir)\"" \
	"-DPACKAGE_DATA_DIR=\"$(pkgdatadir)\""

_with_io_cppenv_ = \
	"-DCONFINI_IO_FLAVOR=CONFINI_POSIX"

_baremetal_cppenv_ = \
	"-DCONFINI_IO_FLAVOR=CONFINI_BAREMETAL"

AM_CPPFLAGS = \
	$(_common_cppenv_) \
	$(_with_io_cppenv_)

AM_CFLAGS = \
	-g -O2 \
	-Wall \
	-pedantic \
	-std=c99 \
	-O2

MOSTLYCLEANFILES = $(am__append_10)
CLEANFILES = \
	confini-baremetal.c \
	confini-baremetal.h \
	libconfini-baremetal.def

lib_LTLIBRARIES = \
	libconfini.la

libconfini_la_LDFLAGS = -version-info $(LTVERSIONINFO) \
	$(am__append_3) $(am__append_4) $(am__append_6)
libconfini_la_LIBADD = 
libconfini_la_SOURCES = $(am__append_2)
nodist_libconfini_la_SOURCES = $(am__append_1) \
	$(am__append_5)
#BUILT_SOURCES = \
#	confini-baremetal.c \
#	confini-baremetal.h

##nodist_noinst_DATA = \
##	.libs/libconfini.def \
##	.libs/libconfini.exp

##AM_RCFLAGS = 
#nodist_include_HEADERS = \
#	built-sources/baremetal/confini.h

include_HEADERS = \
	confini.h

pkgconfig_DATA = \
	libconfini.pc

EXTRA_DIST = \
	libconfini.def \
	libconfini.pc.in \
	winres.rc

UNINSTALLFILES = $(am__append_9)
UNINSTALLHEADERSFILES = \
	'$(DESTDIR)$(includedir)/confini-1.16.h' \
	'$(DESTDIR)$(includedir)/confini-1.h'

_data_insthook_ = $(am__append_8)

# Create `$(PROJECT_CONFNAME)-$(PROJECT_EFFVER).h` and
# `$(PROJECT_CONFNAME)-$(PROJECT_MAJVER).h`
_headers_insthook_ = mv '$(DESTDIR)$(includedir)/confini.h' \
	'$(DESTDIR)$(includedir)/confini-1.16.h' \
	&& (cd '$(DESTDIR)$(includedir)' && $(LN_S) \
	'confini-1.16.h' \
	'confini-1.h'); $(am__append_7)
LOCALSYMBOLS = libconfini-current.def
all: $(BUILT_SOURCES)
	$(MAKE) $(AM_MAKEFLAGS) all-am

.SUFFIXES:
.SUFFIXES: .o .a .c .def .exp .lo .o .obj .rc
$(srcdir)/Makefile.in:  $(srcdir)/Makefile.am  $(am__configure_deps)
	@for dep in $?; do \
	  case '$(am__configure_deps)' in \
	    *$$dep*) \
	      ( cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh ) \
	        && { if test -f $@; then exit 0; else break; fi; }; \
	      exit 1;; \
	  esac; \
	done; \
	echo ' cd $(top_srcdir) && $(AUTOMAKE) --gnu src/Makefile'; \
	$(am__cd) $(top_srcdir) && \
	  $(AUTOMAKE) --gnu src/Makefile
Makefile: $(srcdir)/Makefile.in $(top_builddir)/config.status
	@case '$?' in \
	  *config.status*) \
	    cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh;; \
	  *) \
	    echo ' cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@ $(am__depfiles_maybe)'; \
	    cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@ $(am__depfiles_maybe);; \
	esac;

$(top_builddir)/config.status: $(top_srcdir)/configure $(CONFIG_STATUS_DEPENDENCIES)
	cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh

$(top_srcdir)/configure:  $(am__configure_deps)
	cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh
$(ACLOCAL_M4):  $(am__aclocal_m4_deps)
	cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh
$(am__aclocal_m4_deps):
winres-ac.rc: $(top_builddir)/config.status $(top_srcdir)/autostuff/shadows/src/winres-ac.rc.in
	cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@
${PACKAGE_LOCALNAME}.pc: $(top_builddir)/config.status $(srcdir)/libconfini.pc.in
	cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@

install-libLTLIBRARIES: $(lib_LTLIBRARIES)
	@$(NORMAL_INSTALL)
	@list='$(lib_LTLIBRARIES)'; test -n "$(libdir)" || list=; \
	list2=; for p in $$list; do \
	  if test -f $$p; then \
	    list2="$$list2 $$p"; \
	  else :; fi; \
	done; \
	test -z "$$list2" || { \
	  echo " $(MKDIR_P) '$(DESTDIR)$(libdir)'"; \
	  $(MKDIR_P) "$(DESTDIR)$(libdir)" || exit 1; \
	  echo " $(LIBTOOL) $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=install $(INSTALL) $(INSTALL_STRIP_FLAG) $$list2 '$(DESTDIR)$(libdir)'"; \
	  $(LIBTOOL) $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=install $(INSTALL) $(INSTALL_STRIP_FLAG) $$list2 "$(DESTDIR)$(libdir)"; \
	}

uninstall-libLTLIBRARIES:
	@$(NORMAL_UNINSTALL)
	@list='$(lib_LTLIBRARIES)'; test -n "$(libdir)" || list=; \
	for p in $$list; do \
	  $(am__strip_dir) \
	  echo " $(LIBTOOL) $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=uninstall rm -f '$(DESTDIR)$(libdir)/$$f'"; \
	  $(LIBTOOL) $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=uninstall rm -f "$(DESTDIR)$(libdir)/$$f"; \
	done

clean-libLTLIBRARIES:
	-test -z "$(lib_LTLIBRARIES)" || rm -f $(lib_LTLIBRARIES)
	@list='$(lib_LTLIBRARIES)'; \
	locs=`for p in $$list; do echo $$p; done | \
	      sed 's|^[^/]*$$|.|; s|/[^/]*$$||; s|$$|/so_locations|' | \
	      sort -u`; \
	test -z "$$locs" || { \
	  echo rm -f $${locs}; \
	  rm -f $${locs}; \
	}

libconfini.la: $(libconfini_la_OBJECTS) $(libconfini_la_DEPENDENCIES) $(EXTRA_libconfini_la_DEPENDENCIES) 
	$(AM_V_CCLD)$(libconfini_la_LINK) -rpath $(libdir) $(libconfini_la_OBJECTS) $(libconfini_la_LIBADD) $(LIBS)

mostlyclean-compile:
	-rm -f *.$(OBJEXT)

distclean-compile:
	-rm -f *.tab.c

include ./$(DEPDIR)/confini-baremetal.Plo
include ./$(DEPDIR)/confini.Plo

.c.o:
	$(AM_V_CC)$(COMPILE) -MT $@ -MD -MP -MF $(DEPDIR)/$*.Tpo -c -o $@ $<
	$(AM_V_at)$(am__mv) $(DEPDIR)/$*.Tpo $(DEPDIR)/$*.Po
#	$(AM_V_CC)source='$<' object='$@' libtool=no \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(AM_V_CC_no)$(COMPILE) -c -o $@ $<

.c.obj:
	$(AM_V_CC)$(COMPILE) -MT $@ -MD -MP -MF $(DEPDIR)/$*.Tpo -c -o $@ `$(CYGPATH_W) '$<'`
	$(AM_V_at)$(am__mv) $(DEPDIR)/$*.Tpo $(DEPDIR)/$*.Po
#	$(AM_V_CC)source='$<' object='$@' libtool=no \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(AM_V_CC_no)$(COMPILE) -c -o $@ `$(CYGPATH_W) '$<'`

.c.lo:
	$(AM_V_CC)$(LTCOMPILE) -MT $@ -MD -MP -MF $(DEPDIR)/$*.Tpo -c -o $@ $<
	$(AM_V_at)$(am__mv) $(DEPDIR)/$*.Tpo $(DEPDIR)/$*.Plo
#	$(AM_V_CC)source='$<' object='$@' libtool=yes \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(AM_V_CC_no)$(LTCOMPILE) -c -o $@ $<

mostlyclean-libtool:
	-rm -f *.lo

clean-libtool:
	-rm -rf .libs _libs
install-pkgconfigDATA: $(pkgconfig_DATA)
	@$(NORMAL_INSTALL)
	@list='$(pkgconfig_DATA)'; test -n "$(pkgconfigdir)" || list=; \
	if test -n "$$list"; then \
	  echo " $(MKDIR_P) '$(DESTDIR)$(pkgconfigdir)'"; \
	  $(MKDIR_P) "$(DESTDIR)$(pkgconfigdir)" || exit 1; \
	fi; \
	for p in $$list; do \
	  if test -f "$$p"; then d=; else d="$(srcdir)/"; fi; \
	  echo "$$d$$p"; \
	done | $(am__base_list) | \
	while read files; do \
	  echo " $(INSTALL_DATA) $$files '$(DESTDIR)$(pkgconfigdir)'"; \
	  $(INSTALL_DATA) $$files "$(DESTDIR)$(pkgconfigdir)" || exit $$?; \
	done

uninstall-pkgconfigDATA:
	@$(NORMAL_UNINSTALL)
	@list='$(pkgconfig_DATA)'; test -n "$(pkgconfigdir)" || list=; \
	files=`for p in $$list; do echo $$p; done | sed -e 's|^.*/||'`; \
	dir='$(DESTDIR)$(pkgconfigdir)'; $(am__uninstall_files_from_dir)
install-includeHEADERS: $(include_HEADERS)
	@$(NORMAL_INSTALL)
	@list='$(include_HEADERS)'; test -n "$(includedir)" || list=; \
	if test -n "$$list"; then \
	  echo " $(MKDIR_P) '$(DESTDIR)$(includedir)'"; \
	  $(MKDIR_P) "$(DESTDIR)$(includedir)" || exit 1; \
	fi; \
	for p in $$list; do \
	  if test -f "$$p"; then d=; else d="$(srcdir)/"; fi; \
	  echo "$$d$$p"; \
	done | $(am__base_list) | \
	while read files; do \
	  echo " $(INSTALL_HEADER) $$files '$(DESTDIR)$(includedir)'"; \
	  $(INSTALL_HEADER) $$files "$(DESTDIR)$(includedir)" || exit $$?; \
	done

uninstall-includeHEADERS:
	@$(NORMAL_UNINSTALL)
	@list='$(include_HEADERS)'; test -n "$(includedir)" || list=; \
	files=`for p in $$list; do echo $$p; done | sed -e 's|^.*/||'`; \
	dir='$(DESTDIR)$(includedir)'; $(am__uninstall_files_from_dir)
install-nodist_includeHEADERS: $(nodist_include_HEADERS)
	@$(NORMAL_INSTALL)
	@list='$(nodist_include_HEADERS)'; test -n "$(includedir)" || list=; \
	if test -n "$$list"; then \
	  echo " $(MKDIR_P) '$(DESTDIR)$(includedir)'"; \
	  $(MKDIR_P) "$(DESTDIR)$(includedir)" || exit 1; \
	fi; \
	for p in $$list; do \
	  if test -f "$$p"; then d=; else d="$(srcdir)/"; fi; \
	  echo "$$d$$p"; \
	done | $(am__base_list) | \
	while read files; do \
	  echo " $(INSTALL_HEADER) $$files '$(DESTDIR)$(includedir)'"; \
	  $(INSTALL_HEADER) $$files "$(DESTDIR)$(includedir)" || exit $$?; \
	done

uninstall-nodist_includeHEADERS:
	@$(NORMAL_UNINSTALL)
	@list='$(nodist_include_HEADERS)'; test -n "$(includedir)" || list=; \
	files=`for p in $$list; do echo $$p; done | sed -e 's|^.*/||'`; \
	dir='$(DESTDIR)$(includedir)'; $(am__uninstall_files_from_dir)

ID: $(am__tagged_files)
	$(am__define_uniq_tagged_files); mkid -fID $$unique
tags: tags-am
TAGS: tags

tags-am: $(TAGS_DEPENDENCIES) $(am__tagged_files)
	set x; \
	here=`pwd`; \
	$(am__define_uniq_tagged_files); \
	shift; \
	if test -z "$(ETAGS_ARGS)$$*$$unique"; then :; else \
	  test -n "$$unique" || unique=$$empty_fix; \
	  if test $$# -gt 0; then \
	    $(ETAGS) $(ETAGSFLAGS) $(AM_ETAGSFLAGS) $(ETAGS_ARGS) \
	      "$$@" $$unique; \
	  else \
	    $(ETAGS) $(ETAGSFLAGS) $(AM_ETAGSFLAGS) $(ETAGS_ARGS) \
	      $$unique; \
	  fi; \
	fi
ctags: ctags-am

CTAGS: ctags
ctags-am: $(TAGS_DEPENDENCIES) $(am__tagged_files)
	$(am__define_uniq_tagged_files); \
	test -z "$(CTAGS_ARGS)$$unique" \
	  || $(CTAGS) $(CTAGSFLAGS) $(AM_CTAGSFLAGS) $(CTAGS_ARGS) \
	     $$unique

GTAGS:
	here=`$(am__cd) $(top_builddir) && pwd` \
	  && $(am__cd) $(top_srcdir) \
	  && gtags -i $(GTAGS_ARGS) "$$here"
cscopelist: cscopelist-am

cscopelist-am: $(am__tagged_files)
	list='$(am__tagged_files)'; \
	case "$(srcdir)" in \
	  [\\/]* | ?:[\\/]*) sdir="$(srcdir)" ;; \
	  *) sdir=$(subdir)/$(srcdir) ;; \
	esac; \
	for i in $$list; do \
	  if test -f "$$i"; then \
	    echo "$(subdir)/$$i"; \
	  else \
	    echo "$$sdir/$$i"; \
	  fi; \
	done >> $(top_builddir)/cscope.files

distclean-tags:
	-rm -f TAGS ID GTAGS GRTAGS GSYMS GPATH tags

distdir: $(DISTFILES)
	@srcdirstrip=`echo "$(srcdir)" | sed 's/[].[^$$\\*]/\\\\&/g'`; \
	topsrcdirstrip=`echo "$(top_srcdir)" | sed 's/[].[^$$\\*]/\\\\&/g'`; \
	list='$(DISTFILES)'; \
	  dist_files=`for file in $$list; do echo $$file; done | \
	  sed -e "s|^$$srcdirstrip/||;t" \
	      -e "s|^$$topsrcdirstrip/|$(top_builddir)/|;t"`; \
	case $$dist_files in \
	  */*) $(MKDIR_P) `echo "$$dist_files" | \
			   sed '/\//!d;s|^|$(distdir)/|;s,/[^/]*$$,,' | \
			   sort -u` ;; \
	esac; \
	for file in $$dist_files; do \
	  if test -f $$file || test -d $$file; then d=.; else d=$(srcdir); fi; \
	  if test -d $$d/$$file; then \
	    dir=`echo "/$$file" | sed -e 's,/[^/]*$$,,'`; \
	    if test -d "$(distdir)/$$file"; then \
	      find "$(distdir)/$$file" -type d ! -perm -700 -exec chmod u+rwx {} \;; \
	    fi; \
	    if test -d $(srcdir)/$$file && test $$d != $(srcdir); then \
	      cp -fpR $(srcdir)/$$file "$(distdir)$$dir" || exit 1; \
	      find "$(distdir)/$$file" -type d ! -perm -700 -exec chmod u+rwx {} \;; \
	    fi; \
	    cp -fpR $$d/$$file "$(distdir)$$dir" || exit 1; \
	  else \
	    test -f "$(distdir)/$$file" \
	    || cp -p $$d/$$file "$(distdir)/$$file" \
	    || exit 1; \
	  fi; \
	done
check-am: all-am
check: $(BUILT_SOURCES)
	$(MAKE) $(AM_MAKEFLAGS) check-am
all-am: Makefile $(LTLIBRARIES) $(DATA) $(HEADERS)
installdirs:
	for dir in "$(DESTDIR)$(libdir)" "$(DESTDIR)$(pkgconfigdir)" "$(DESTDIR)$(includedir)" "$(DESTDIR)$(includedir)"; do \
	  test -z "$$dir" || $(MKDIR_P) "$$dir"; \
	done
install: $(BUILT_SOURCES)
	$(MAKE) $(AM_MAKEFLAGS) install-am
install-exec: install-exec-am
install-data: install-data-am
uninstall: uninstall-am

install-am: all-am
	@$(MAKE) $(AM_MAKEFLAGS) install-exec-am install-data-am

installcheck: installcheck-am
install-strip:
	if test -z '$(STRIP)'; then \
	  $(MAKE) $(AM_MAKEFLAGS) INSTALL_PROGRAM="$(INSTALL_STRIP_PROGRAM)" \
	    install_sh_PROGRAM="$(INSTALL_STRIP_PROGRAM)" INSTALL_STRIP_FLAG=-s \
	      install; \
	else \
	  $(MAKE) $(AM_MAKEFLAGS) INSTALL_PROGRAM="$(INSTALL_STRIP_PROGRAM)" \
	    install_sh_PROGRAM="$(INSTALL_STRIP_PROGRAM)" INSTALL_STRIP_FLAG=-s \
	    "INSTALL_PROGRAM_ENV=STRIPPROG='$(STRIP)'" install; \
	fi
mostlyclean-generic:
	-test -z "$(MOSTLYCLEANFILES)" || rm -f $(MOSTLYCLEANFILES)

clean-generic:
	-test -z "$(CLEANFILES)" || rm -f $(CLEANFILES)

distclean-generic:
	-test -z "$(CONFIG_CLEAN_FILES)" || rm -f $(CONFIG_CLEAN_FILES)
	-test . = "$(srcdir)" || test -z "$(CONFIG_CLEAN_VPATH_FILES)" || rm -f $(CONFIG_CLEAN_VPATH_FILES)

maintainer-clean-generic:
	@echo "This command is intended for maintainers to use"
	@echo "it deletes files that may require special tools to rebuild."
	-test -z "$(BUILT_SOURCES)" || rm -f $(BUILT_SOURCES)
clean: clean-am

clean-am: clean-generic clean-libLTLIBRARIES clean-libtool clean-local \
	mostlyclean-am

distclean: distclean-am
	-rm -rf ./$(DEPDIR)
	-rm -f Makefile
distclean-am: clean-am distclean-compile distclean-generic \
	distclean-tags

dvi: dvi-am

dvi-am:

html: html-am

html-am:

info: info-am

info-am:

install-data-am: install-includeHEADERS install-nodist_includeHEADERS \
	install-pkgconfigDATA
	@$(NORMAL_INSTALL)
	$(MAKE) $(AM_MAKEFLAGS) install-data-hook
install-dvi: install-dvi-am

install-dvi-am:

install-exec-am: install-libLTLIBRARIES

install-html: install-html-am

install-html-am:

install-info: install-info-am

install-info-am:

install-man:

install-pdf: install-pdf-am

install-pdf-am:

install-ps: install-ps-am

install-ps-am:

installcheck-am:

maintainer-clean: maintainer-clean-am
	-rm -rf ./$(DEPDIR)
	-rm -f Makefile
maintainer-clean-am: distclean-am maintainer-clean-generic

mostlyclean: mostlyclean-am

mostlyclean-am: mostlyclean-compile mostlyclean-generic \
	mostlyclean-libtool

pdf: pdf-am

pdf-am:

ps: ps-am

ps-am:

uninstall-am: uninstall-includeHEADERS uninstall-libLTLIBRARIES \
	uninstall-local uninstall-nodist_includeHEADERS \
	uninstall-pkgconfigDATA

.MAKE: all check install install-am install-data-am install-strip

.PHONY: CTAGS GTAGS TAGS all all-am check check-am clean clean-generic \
	clean-libLTLIBRARIES clean-libtool clean-local cscopelist-am \
	ctags ctags-am distclean distclean-compile distclean-generic \
	distclean-libtool distclean-tags distdir dvi dvi-am html \
	html-am info info-am install install-am install-data \
	install-data-am install-data-hook install-dvi install-dvi-am \
	install-exec install-exec-am install-html install-html-am \
	install-includeHEADERS install-info install-info-am \
	install-libLTLIBRARIES install-man \
	install-nodist_includeHEADERS install-pdf install-pdf-am \
	install-pkgconfigDATA install-ps install-ps-am install-strip \
	installcheck installcheck-am installdirs maintainer-clean \
	maintainer-clean-generic mostlyclean mostlyclean-compile \
	mostlyclean-generic mostlyclean-libtool pdf pdf-am ps ps-am \
	tags tags-am uninstall uninstall-am uninstall-includeHEADERS \
	uninstall-libLTLIBRARIES uninstall-local \
	uninstall-nodist_includeHEADERS uninstall-pkgconfigDATA

.PRECIOUS: Makefile


###############################################################################
###############################################################################

clean-local:
	-rm -rf 'built-sources';

install-data-hook:
	$(_data_insthook_)

uninstall-local:
	-rm -f $(UNINSTALLFILES);

# Install only the headers
.PHONY: install-headers
install-headers: install-includeHEADERS install-nodist_includeHEADERS
	$(_headers_insthook_)

# Uninstall only the headers
.PHONY: uninstall-headers
uninstall-headers: uninstall-includeHEADERS uninstall-nodist_includeHEADERS
	-rm -f $(UNINSTALLHEADERSFILES);

# Inference rule

#.rc.lo:
#	$(LIBTOOL) $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --tag=RC --mode=compile \
#	$(RC) $(AM_RCFLAGS) $(RCFLAGS) $< -o $@;

# Inference rules

#.a.def:
#	$(DLLTOOL) -z '$@' --export-all-symbols '$<' && $(SED) -i '/^\s*\;/{d};' \
#	'$@';

#.o.def:
#	$(DLLTOOL) -z '$@' --export-all-symbols '$<' && $(SED) -i '/^\s*\;/{d};' \
#	'$@';

#.a.exp:
#	$(DLLTOOL) -e '$@' --export-all-symbols '$<';

#.o.exp:
#	$(DLLTOOL) -e '$@' --export-all-symbols '$<';

# .PHONY: current-symbols
# current-symbols: libconfini.la
#	@$(MAKE) '.libs/libconfini.def' && \
#	cp '.libs/libconfini.def' '$(LOCALSYMBOLS)';

# Accept `dev/marked-sources/confini-marked.c` without amendments
#$(srcdir)/confini.c: \
# $(top_srcdir)/dev/marked-sources/confini-marked.c \
# $(top_srcdir)/dev/hackings/all/confini-metadata.c \
# $(top_srcdir)/dev/hackings/baremetal/confini-header.c
#	@{ echo 'Creating $@...'; sed '/!\s*END_EXCEPTION\s*(CONFINI_C_METADATA)\s*!/{r '"$(top_srcdir)/dev/hackings/all/confini-metadata.c"$$'\n};/!\s*ENTRY_POINT\s*(CONFINI_C_METADATA)\s*!/{r '"$(top_srcdir)/dev/hackings/all/confini-metadata.c"$$'\n};/!\s*START_EXCEPTION\s*(CONFINI_C_METADATA)\s*!/,/!\s*END_EXCEPTION\s*(CONFINI_C_METADATA)\s*!/{d};/!\s*START_EXCEPTION\s*(CONFINI_C_METADATA)\s*!/{d};''/!\s*START_EXCEPTION\s*([^)]*)\s*!/{d};/!\s*END_EXCEPTION\s*([^)]*)\s*!/{d};/!\s*ENTRY_POINT\s*([^)]*)\s*!/{d};/!\s*START_OMISSION\s*!/,/!\s*END_OMISSION\s*!/{d}' "$(top_srcdir)/dev/marked-sources/confini-marked.c" > "$@"; };

# Accept `dev/marked-sources/confini-marked.h` without amendments
#$(srcdir)/confini.h: \
# $(top_srcdir)/dev/marked-sources/confini-marked.h \
# $(top_srcdir)/dev/hackings/all/confini-metadata.h
#	@{ echo 'Creating $@...'; sed '/!\s*END_EXCEPTION\s*(CONFINI_H_METADATA)\s*!/{r '"$(top_srcdir)/dev/hackings/all/confini-metadata.h"$$'\n};/!\s*ENTRY_POINT\s*(CONFINI_H_METADATA)\s*!/{r '"$(top_srcdir)/dev/hackings/all/confini-metadata.h"$$'\n};/!\s*START_EXCEPTION\s*(CONFINI_H_METADATA)\s*!/,/!\s*END_EXCEPTION\s*(CONFINI_H_METADATA)\s*!/{d};/!\s*START_EXCEPTION\s*(CONFINI_H_METADATA)\s*!/{d};''/!\s*START_EXCEPTION\s*([^)]*)\s*!/{d};/!\s*END_EXCEPTION\s*([^)]*)\s*!/{d};/!\s*ENTRY_POINT\s*([^)]*)\s*!/{d};/!\s*START_OMISSION\s*!/,/!\s*END_OMISSION\s*!/{d}' "$(top_srcdir)/dev/marked-sources/confini-marked.h" > "$@"; };

##$(srcdir)/libconfini.def: $(srcdir)/confini.c $(srcdir)/confini.h
##	@$(MAKE) LOCALSYMBOLS='$@' current-symbols;

#$(top_builddir)/no-dist/.archived/$(nonportfile):
#	@$(MAKE) -C '$(top_builddir)' 'no-dist/.archived/$(nonportfile)';

#$(top_builddir)/no-dist/hackings/baremetal/c-standard-library.h: \
# $(top_builddir)/no-dist/.archived/$(nonportfile)
#	@$(MAKE) -C '$(top_builddir)' \
#	'no-dist/hackings/baremetal/c-standard-library.h';

##libconfini-baremetal.def: confini-baremetal.c confini-baremetal.h
##	@$(MAKE) LOCALSYMBOLS='$@' current-symbols;

# Amend `dev/marked-sources/confini-marked.c`
built-sources/baremetal/confini.c: \
 $(top_srcdir)/dev/marked-sources/confini-marked.c \
 $(top_srcdir)/dev/hackings/all/confini-metadata.c \
 $(top_srcdir)/dev/hackings/baremetal/str2num.c \
 $(top_srcdir)/dev/hackings/baremetal/confini-header.c
	@$(MKDIR_P) '$(@D)' && { echo 'Creating $@...'; sed '/!\s*END_EXCEPTION\s*(CONFINI_C_METADATA)\s*!/{r '"$(top_srcdir)/dev/hackings/all/confini-metadata.c"$$'\n};/!\s*ENTRY_POINT\s*(CONFINI_C_METADATA)\s*!/{r '"$(top_srcdir)/dev/hackings/all/confini-metadata.c"$$'\n};/!\s*START_EXCEPTION\s*(CONFINI_C_METADATA)\s*!/,/!\s*END_EXCEPTION\s*(CONFINI_C_METADATA)\s*!/{d};/!\s*START_EXCEPTION\s*(CONFINI_C_METADATA)\s*!/{d};''/!\s*START_EXCEPTION\s*(IO_FLAVORS)\s*!/,/!\s*END_EXCEPTION\s*(IO_FLAVORS)\s*!/{d};/!\s*START_EXCEPTION\s*(IO_FLAVORS)\s*!/{d};''/!\s*START_EXCEPTION\s*(STANDARD_HEADERS)\s*!/,/!\s*END_EXCEPTION\s*(STANDARD_HEADERS)\s*!/{d};/!\s*START_EXCEPTION\s*(STANDARD_HEADERS)\s*!/{d};''/!\s*END_EXCEPTION\s*(CONFINI_HEADER)\s*!/{r '"$(top_srcdir)/dev/hackings/baremetal/confini-header.c"$$'\n};/!\s*ENTRY_POINT\s*(CONFINI_HEADER)\s*!/{r '"$(top_srcdir)/dev/hackings/baremetal/confini-header.c"$$'\n};/!\s*START_EXCEPTION\s*(CONFINI_HEADER)\s*!/,/!\s*END_EXCEPTION\s*(CONFINI_HEADER)\s*!/{d};/!\s*START_EXCEPTION\s*(CONFINI_HEADER)\s*!/{d};''/!\s*START_EXCEPTION\s*(IO_ALIASES)\s*!/,/!\s*END_EXCEPTION\s*(IO_ALIASES)\s*!/{d};/!\s*START_EXCEPTION\s*(IO_ALIASES)\s*!/{d};''/!\s*START_EXCEPTION\s*(IO_FUNCTIONS)\s*!/,/!\s*END_EXCEPTION\s*(IO_FUNCTIONS)\s*!/{d};/!\s*START_EXCEPTION\s*(IO_FUNCTIONS)\s*!/{d};''/!\s*END_EXCEPTION\s*(LIBC_STR2NUM)\s*!/{r '"$(top_srcdir)/dev/hackings/baremetal/str2num.c"$$'\n};/!\s*ENTRY_POINT\s*(LIBC_STR2NUM)\s*!/{r '"$(top_srcdir)/dev/hackings/baremetal/str2num.c"$$'\n};/!\s*START_EXCEPTION\s*(LIBC_STR2NUM)\s*!/,/!\s*END_EXCEPTION\s*(LIBC_STR2NUM)\s*!/{d};/!\s*START_EXCEPTION\s*(LIBC_STR2NUM)\s*!/{d};''/!\s*START_EXCEPTION\s*([^)]*)\s*!/{d};/!\s*END_EXCEPTION\s*([^)]*)\s*!/{d};/!\s*ENTRY_POINT\s*([^)]*)\s*!/{d};/!\s*START_OMISSION\s*!/,/!\s*END_OMISSION\s*!/{d}' "$(top_srcdir)/dev/marked-sources/confini-marked.c" > "$@"; } ;

# Amend `dev/marked-sources/confini-marked.h`
built-sources/baremetal/confini.h: \
 $(top_srcdir)/dev/marked-sources/confini-marked.h \
 $(top_srcdir)/dev/hackings/all/confini-metadata.h \
 $(top_srcdir)/dev/hackings/baremetal/str2num.h \
 $(top_builddir)/no-dist/hackings/baremetal/c-standard-library.h
	@$(MKDIR_P) '$(@D)' && { echo 'Creating $@...'; sed '/!\s*END_EXCEPTION\s*(CONFINI_H_METADATA)\s*!/{r '"$(top_srcdir)/dev/hackings/all/confini-metadata.h"$$'\n};/!\s*ENTRY_POINT\s*(CONFINI_H_METADATA)\s*!/{r '"$(top_srcdir)/dev/hackings/all/confini-metadata.h"$$'\n};/!\s*START_EXCEPTION\s*(CONFINI_H_METADATA)\s*!/,/!\s*END_EXCEPTION\s*(CONFINI_H_METADATA)\s*!/{d};/!\s*START_EXCEPTION\s*(CONFINI_H_METADATA)\s*!/{d};''/!\s*END_EXCEPTION\s*(STANDARD_HEADERS)\s*!/{r '"$(top_builddir)/no-dist/hackings/baremetal/c-standard-library.h"$$'\n};/!\s*ENTRY_POINT\s*(STANDARD_HEADERS)\s*!/{r '"$(top_builddir)/no-dist/hackings/baremetal/c-standard-library.h"$$'\n};/!\s*START_EXCEPTION\s*(STANDARD_HEADERS)\s*!/,/!\s*END_EXCEPTION\s*(STANDARD_HEADERS)\s*!/{d};/!\s*START_EXCEPTION\s*(STANDARD_HEADERS)\s*!/{d};''/!\s*START_EXCEPTION\s*(IO_FUNCTIONS)\s*!/,/!\s*END_EXCEPTION\s*(IO_FUNCTIONS)\s*!/{d};/!\s*START_EXCEPTION\s*(IO_FUNCTIONS)\s*!/{d};''/!\s*END_EXCEPTION\s*(LIBC_STR2NUM)\s*!/{r '"$(top_srcdir)/dev/hackings/baremetal/str2num.h"$$'\n};/!\s*ENTRY_POINT\s*(LIBC_STR2NUM)\s*!/{r '"$(top_srcdir)/dev/hackings/baremetal/str2num.h"$$'\n};/!\s*START_EXCEPTION\s*(LIBC_STR2NUM)\s*!/,/!\s*END_EXCEPTION\s*(LIBC_STR2NUM)\s*!/{d};/!\s*START_EXCEPTION\s*(LIBC_STR2NUM)\s*!/{d};''/!\s*START_EXCEPTION\s*([^)]*)\s*!/{d};/!\s*END_EXCEPTION\s*([^)]*)\s*!/{d};/!\s*ENTRY_POINT\s*([^)]*)\s*!/{d};/!\s*START_OMISSION\s*!/,/!\s*END_OMISSION\s*!/{d}' "$(top_srcdir)/dev/marked-sources/confini-marked.h" > "$@"; } ;

# Symbolic link
confini-baremetal.c: \
 built-sources/baremetal/confini.c
	@rm -f '$@' && $(LN_S) '$<' '$@';

# Symbolic link
confini-baremetal.h: \
 built-sources/baremetal/confini.h
	@rm -f '$@' && $(LN_S) '$<' '$@';

# User's rule for forcing non-phony targets to be built, as in `make
# EXPIRE='confini.c confini.h' confini.c confini.h` or (equivalently) `make
# EXPIRE='confini.c confini.h' refresh`
.PHONY: $(EXPIRE) refresh
refresh: $(EXPIRE)

# Tell versions [3.59,3.63) of GNU make to not export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
