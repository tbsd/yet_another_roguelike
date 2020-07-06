#!/bin/bash

# remove previous executable
rm build/rogues_party

# build project
cd build
cmake .. >> /dev/null
cmake --build .
cd ..

# create documentation
# doxygen Doxyfile >> /dev/null

