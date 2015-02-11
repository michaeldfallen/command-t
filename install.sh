#!/bin/sh

thisdir="$( dirname "$0" )"

cd "$thisdir/ruby/command-t"

ruby extconf.rb
make

cd "$thisdir"

export ARCHFLAGS="-arch i386"
make
