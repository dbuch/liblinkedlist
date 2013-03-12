#!/bin/sh

set -e

echo '## Initializing build system'
intltoolize --force --automake
autoreconf --force --install --symlink
echo '## Done. You can now ./configure build system'
