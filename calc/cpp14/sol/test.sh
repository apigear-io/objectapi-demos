#!/bin/bash

export DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )";
cd $DIR;
rm -rf build/ && mkdir -p build && cd build;
mkdir -p buildapigear_calc && cd buildapigear_calc;
pushd ../../apigear_calc;
conan source .
popd
conan install --build missing ../../apigear_calc #&& conan build ../../apigear_calc && cmake ../../apigear_calc && make && make check;
# conan create ../../apigear_calc demo/apigear_calc_testing
cd ..;
