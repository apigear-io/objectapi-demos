#include "tracer.h"
#include "../../shared/traceclient.h"

CalculatorTracer::CalculatorTracer()
{
}

void CalculatorTracer::capture_state(AbstractCalculator* obj)
{
    const QVariantMap &fields_ {
        { "total", QVariant::fromValue(obj->total()) },
    };
    TraceClient::instance()->state("apigear.calc.Calculator#_state", fields_);
    qDebug() << "state: " <<  "apigear.calc" <<  "Calculator" << "_state" << fields_;
}
void CalculatorTracer::trace_add(int a)
{
    const QVariantMap &fields_ {
        { "a", QVariant::fromValue(a) },

    };
    TraceClient::instance()->call("apigear.calc.Calculator#add", fields_);
}
void CalculatorTracer::trace_substract(int a)
{
    const QVariantMap &fields_ {
        { "a", QVariant::fromValue(a) },

    };
    TraceClient::instance()->call("apigear.calc.Calculator#substract", fields_);
}
void CalculatorTracer::trace_multiply(int a)
{
    const QVariantMap &fields_ {
        { "a", QVariant::fromValue(a) },

    };
    TraceClient::instance()->call("apigear.calc.Calculator#multiply", fields_);
}
void CalculatorTracer::trace_divide(int a)
{
    const QVariantMap &fields_ {
        { "a", QVariant::fromValue(a) },

    };
    TraceClient::instance()->call("apigear.calc.Calculator#divide", fields_);
}
void CalculatorTracer::trace_clear()
{
    const QVariantMap &fields_ {

    };
    TraceClient::instance()->call("apigear.calc.Calculator#clear", fields_);
}