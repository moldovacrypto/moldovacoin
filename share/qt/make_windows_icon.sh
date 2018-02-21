#!/bin/bash
# create multiresolution windows icon
ICON_DST=../../src/qt/res/icons/moldovacoin.ico

convert ../../src/qt/res/icons/moldovacoin-16.png ../../src/qt/res/icons/moldovacoin-32.png ../../src/qt/res/icons/moldovacoin-48.png ${ICON_DST}
