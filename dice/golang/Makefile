.PHONY: all clean gen build watch

all: clean gen
	
clean:
	rm -rf ini/**

gen:
	cd ../../../objectapi-generator/ && yarn dev:gen --rules templates/golang/oapi.rules.yml --output ../objectapi-demos/dice/golang/ini ../objectapi-demos/dice/apis --scaffold

force:
	cd ../../../objectapi-generator/ && yarn dev:gen --rules templates/golang/oapi.rules.yml --output ../objectapi-demos/dice/golang/ini ../objectapi-demos/dice/apis  --force --scaffold

temp:
	cd ../../../objectapi-generator/ && yarn dev:gen --rules templates/golang/oapi.rules.yml --output ../objectapi-demos/dice/golang/temp ../objectapi-demos/dice/apis --force --scaffold

watch:
	nodemon