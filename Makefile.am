ACLOCAL_AMFLAGS = -I m4 ${ACLOCAL_FLAGS}
AM_MAKEFLAGS = --no-print-directory
AUTOMAKE_OPTIONS = color-tests parallel-tests

noinst_PROGRAMS = example test-liblinkedlist

noinst_LTLIBRARIES = liblinkedlist.la \
		      debug.la

liblinkedlist_la_SOURCES = src/linkedlist.h src/linkedlist.c
liblinkedlist_la_LDFLAGS = -module -avoid-version -shared

debug_la_SOURCES = src/debug.h
debug_la_LDFLAGS = -module -avoid-version -shared

example_SOURCES = src/example.c
example_LDADD = liblinkedlist.la \
		debug.la

test_liblinkedlist_SOURCES = src/tests/test-liblinkedlist.c
test_liblinkedlist_LDADD = liblinkedlist.la \
			   debug.la

EXTRA_DIST = m4/NOTES
dist_noinst_SCRIPTS = autogen.sh
