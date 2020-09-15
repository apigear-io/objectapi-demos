#!/bin/bash

export DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )";
cd $DIR;
rm -rf build/ && mkdir -p build && cd build;
mkdir -p buildapigear_game && cd buildapigear_game;
pushd ../../apigear_game;
conan source .
popd
# conan install --build missing ../../apigear_game && conan build ../../apigear_game && cmake ../../apigear_game && make && make check;
conan install --build missing ../../apigear_game && conan create ../../apigear_game demo/apigear_game_testing
cd ..;
