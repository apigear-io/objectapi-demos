.PHONY: all clean gen build watch build_ini build_sol

all: clean gen

GENDIR = ../../../objectapi-generator/
GENERATOR = yarn dev:gen
RULES = templates/typescript/oapi.rules.yml
OUTPUT = ../objectapi-demos/dice/typescript/ini
TEMP = ../objectapi-demos/dice/typescript/temp
APIS = ../objectapi-demos/dice/apis

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
	cd build_ini && yarn test


build_sol:
	mkdir -p build_sol
	cd build_sol && yarn test
