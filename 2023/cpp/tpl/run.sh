#!/bin/bash
name=${PWD##*/}
g++ src/*.cpp -o $name
./$name
