#!/bin/bash

set -e

(cd build ; make)
build/gfxtest
