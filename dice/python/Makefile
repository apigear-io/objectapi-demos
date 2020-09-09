.PHONY: all clean gen build watch

all: clean gen

GENDIR = ../../../objectapi-generator/
GENERATOR = yarn dev:gen
RULES = templates/python/oapi.rules.yml
OUTPUT = ../objectapi-demos/dice/python/ini
TEMP = ../objectapi-demos/dice/python/temp
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