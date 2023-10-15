#!/bin/bash

project=name
cd build/
make
cd src/
./$project
