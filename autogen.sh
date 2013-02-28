#!/bin/sh -e

test -n "$srcdir" || srcdir=.

echo '## Initializing build system'
autoreconf -f -i --install --verbose "$srcdir"
test -n "$NOCONFIGURE" || "$srcdir/configure" "$0"
echo '## Done. You can now ./configure build system'
