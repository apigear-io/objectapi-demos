#include "tracer.h"
#include "apigear_calc.trace.h"

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

CalculatorTracer::CalculatorTracer()
{
}

void CalculatorTracer::capture_state(CalculatorBase* obj)
{
    Poco::JSON::Object fields_;
    fields_.set("total", toJSON(obj->total()));
    Tracer::instance()->state("apigear.calc.Calculator#_state", fields_);
    // std::cout << "state: " <<  "apigear.calc" <<  "Calculator" << "_state" << fields_;
}

void CalculatorTracer::trace_add(int a)
{
    Poco::JSON::Object fields_;
    fields_.set("a", toJSON(a));
    Tracer::instance()->call("apigear.calc.Calculator#add", fields_);
}

void CalculatorTracer::trace_substract(int a)
{
    Poco::JSON::Object fields_;
    fields_.set("a", toJSON(a));
    Tracer::instance()->call("apigear.calc.Calculator#substract", fields_);
}

void CalculatorTracer::trace_multiply(int a)
{
    Poco::JSON::Object fields_;
    fields_.set("a", toJSON(a));
    Tracer::instance()->call("apigear.calc.Calculator#multiply", fields_);
}

void CalculatorTracer::trace_divide(int a)
{
    Poco::JSON::Object fields_;
    fields_.set("a", toJSON(a));
    Tracer::instance()->call("apigear.calc.Calculator#divide", fields_);
}

void CalculatorTracer::trace_clear()
{
    Poco::JSON::Object fields_;
    Tracer::instance()->call("apigear.calc.Calculator#clear", fields_);
}
