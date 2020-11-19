#!/bin/bash

mkdir -p lib
cd lib

git clone https://github.com/alecthomas/entityx

git clone https://github.com/chronoxor/CppServer
cd CppServer
gil update
cd .. 

git clone https://github.com/nlohmann/json

git clone https://github.com/google/flatbuffers

cd ..
