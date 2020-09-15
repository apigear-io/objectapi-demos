#include "tracer.h"
#include "apigear_game.trace.h"

std::string toJSON(const int& obj)
{
    return std::to_string(obj);
}

const std::string& toJSON(const std::string& obj)
{
    return obj;
}

template<typename T>
Poco::JSON::Array toJSON(const std::list<T>& listObj)
{
    Poco::JSON::Array returnVal;

    for (auto&& obj : listObj) {
        returnVal.add(toJSON(obj));
    }

    return returnVal;
}

DiceTracer::DiceTracer()
{
}

void DiceTracer::capture_state(DiceBase* obj)
{
    Poco::JSON::Object fields_;
    fields_.set("value", toJSON(obj->value()));
    Tracer::instance()->state("apigear.game.Dice#_state", fields_);
    // std::cout << "state: " <<  "apigear.game" <<  "Dice" << "_state" << fields_;
}

void DiceTracer::trace_toss()
{
    Poco::JSON::Object fields_;
    Tracer::instance()->call("apigear.game.Dice#toss", fields_);
}

RandomTracer::RandomTracer()
{
}

void RandomTracer::capture_state(RandomBase* obj)
{
    Poco::JSON::Object fields_;
    Tracer::instance()->state("apigear.game.Random#_state", fields_);
    // std::cout << "state: " <<  "apigear.game" <<  "Random" << "_state" << fields_;
}

void RandomTracer::trace_generate(int min, int max)
{
    Poco::JSON::Object fields_;
    fields_.set("min", toJSON(min));
    fields_.set("max", toJSON(max));
    Tracer::instance()->call("apigear.game.Random#generate", fields_);
}
