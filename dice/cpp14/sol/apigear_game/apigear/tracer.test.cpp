/**
Tracer Test
Copyright (C) 2020 ApiGear UG
*/
#include "catch2/catch.hpp"
#include "tracer.h"

TEST_CASE("Testing Tracer", "[Tracer]"){
    Tracer* testTracer = testTracer->instance();
    std::string modulename = "tracer.test.org";
    std::string interfacename = "tester";

    // setup your test
    SECTION("Test operation call") {
        std::string symbol = modulename + "." + interfacename+"#testCall";
        Poco::JSON::Object fields;

        Poco::JSON::Object obj(true);
        obj.set("Age", "5");
        obj.set("Profession", "Programmer");
        fields.set("Annabelle",obj);

        testTracer->call(symbol, fields);
    }
    
    SECTION("Test operation signal") {
        // Do implement test here
    }

    SECTION("Test operation state") {
        std::string symbol = modulename + "." + interfacename+"#_state";
        Poco::JSON::Object fields;

        fields.set("Age", "5");
        fields.set("Name", "Apigear");

        testTracer->state(symbol, fields);
    }

    Poco::Thread::sleep(500);
}
