.PHONY: all clean gen build watch

all: clean gen
	
clean:
	rm -rf ini/**

gen:
	cd ../../../objectapi-generator/ && yarn dev:gen --rules templates/golang/oapi.rules.yml --output ../objectapi-demos/calc/golang/ini ../objectapi-demos/calc/apis --scaffold

force:
	cd ../../../objectapi-generator/ && yarn dev:gen --rules templates/golang/oapi.rules.yml --output ../objectapi-demos/calc/golang/ini ../objectapi-demos/calc/apis  --force --scaffold

temp:
	cd ../../../objectapi-generator/ && yarn dev:gen --rules templates/golang/oapi.rules.yml --output ../objectapi-demos/calc/golang/temp ../objectapi-demos/calc/apis --force --scaffold

watch:
	nodemon