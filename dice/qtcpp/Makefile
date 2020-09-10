.PHONY: all clean gen build watch build_ini build_sol

all: clean gen

GENDIR = ../../../objectapi-generator/
GENERATOR = yarn dev:gen
RULES = templates/qtcpp/oapi.rules.yml
OUTPUT = ../objectapi-demos/dice/qtcpp/ini
TEMP = ../objectapi-demos/dice/qtcpp/temp
APIS = ../objectapi-demos/dice/apis
CMAKE_PREFIX = ~/Qt/5.14.0/clang_64
clean:
	rm -rf ini/**


gen:
	cd ${GENDIR} && ${GENERATOR} --rules ${RULES} --output ${OUTPUT} ${APIS} --scaffold

force:
	cd ${GENDIR} && ${GENERATOR} --rules ${RULES} --output ${OUTPUT} ${APIS} --scaffold --force

temp:
	cd ${GENDIR} && ${GENERATOR} --rules ${RULES} --output ${TEMP} ${APIS} --scaffold --force

watch:
	nodemon

build_ini:
	mkdir -p build_ini
	cd build_ini && CMAKE_PREFIX_PATH=${CMAKE_PREFIX} cmake ../ini -DBUILD_TESTING=ON
	cd build_ini && make -j8
	cd build_ini && make check


build_sol:
	mkdir -p build_sol
	cd build_sol && CMAKE_PREFIX_PATH=${CMAKE_PREFIX} cmake ../sol -DBUILD_TESTING=ON
	cd build_sol && make -j8
	cd build_sol && make check
