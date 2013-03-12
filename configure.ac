AC_PREREQ([2.64])

AC_INIT([liblinkedlist],
        [0.0.1],
        [https://github.com/dbuch/liblinkedlist])

AC_CONFIG_SRCDIR([src/example.c])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_AUX_DIR([build-aux])

AC_USE_SYSTEM_EXTENSIONS
AC_SYS_LARGEFILE
AM_INIT_AUTOMAKE([foreign 1.11 -Wall -Wno-portability silent-rules tar-pax no-dist-gzip dist-xz subdir-objects check-news])
AM_SILENT_RULES([yes])

LT_PREREQ(2.2)
LT_INIT([disable-static])

# i18n stuff for the PolicyKit policy files
IT_PROG_INTLTOOL([0.40.0])


AC_PROG_MKDIR_P
AC_PROG_LN_S
AC_PROG_SED
AC_PROG_GREP
AC_PROG_AWK

AC_PROG_CC
AC_PROG_CC_C99
AM_PROG_CC_C_O
AC_PROG_GCC_TRADITIONAL

AC_SUBST([dbusinterfacedir], [$with_dbusinterfacedir])
AC_SUBST([bashcompletiondir], [$with_bashcompletiondir])
AC_SUBST([pamlibdir], [$with_pamlibdir])
AC_SUBST([rootprefix], [$with_rootprefix])
AC_SUBST([rootlibdir], [$with_rootlibdir])

AC_CONFIG_FILES([Makefile po/Makefile.in])

AC_OUTPUT
