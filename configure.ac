AC_PREREQ([2.69])
AC_INIT([liblinkedlist], [0.01], [https://github.com/dbuch/liblinkedlist/issues])
AC_CONFIG_HEADERS([src/linkedlist.h])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE([1.11 subdir-objects -Wall -Werror])
LT_INIT

# Checks for programs.
AC_PROG_CC
AC_PROG_CC_C99
AM_PROG_CC_C_O
AM_PROG_LIBTOOL

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h assert.h optget.h])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
