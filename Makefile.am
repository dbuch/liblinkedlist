ACLOCAL_AMFLAGS = -I m4 ${ACLOCAL_FLAGS}
AM_MAKEFLAGS = --no-print-directory
AUTOMAKE_OPTIONS = color-tests parallel-tests

include_HEADERS = src/linkedlist.h src/linkedlist.c
bin_PROGRAMS = example \
	       test

noinst_LTLIBRARIES = liblinkedlist.la
liblinkedlist_la_SOURCES = src/linkedlist.h src/linkedlist.c
liblinkedlist_la_LDFLAGS = -module -avoid-version -shared

example_SOURCES = src/example.c
example_LDADD = liblinkedlist.la

test_SOURCES = src/test/test.c
test_LDADD = liblinkedlist.la

EXTRA_DIST = m4/NOTES
dist_noinst_SCRIPTS = autogen.sh
