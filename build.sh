#!/bin/bash

# remove previous executable
rm build/tbsd_roguelike

# build project
cd build
cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=ON >> /dev/null
cmake --build .
cd ..

# create documentation
# doxygen Doxyfile >> /dev/null

