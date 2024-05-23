#!/bin/bash
name=out.temp
g++ src/*.cpp -o $name
./$name
rm -f $name
