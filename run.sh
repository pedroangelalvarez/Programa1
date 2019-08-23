#!/bin/bash

{
    cmake --build ./build
    ./build/Programa1
} || {
    ./build.sh
    cmake --build ./build
    ./build/Programa1
}
