#!/usr/bin/env bash

mkdir -p ninja-build-debug && cd ninja-build-debug
rm -rf ./*
cmake -G Ninja ..
ninja
