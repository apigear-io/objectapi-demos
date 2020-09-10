#include "tracer.h"
#include "../shared/traceclient.h"

DiceTracer::DiceTracer()
{
}

void DiceTracer::capture_state(AbstractDice* obj)
{
    const QVariantMap &fields_ {
        { "value", QVariant::fromValue(obj->value()) },
    };
    TraceClient::instance()->state("apigear.game.Dice#_state", fields_);
    qDebug() << "state: " <<  "apigear.game" <<  "Dice" << "_state" << fields_;
}
void DiceTracer::trace_toss()
{
    const QVariantMap &fields_ {

    };
    TraceClient::instance()->call("apigear.game.Dice#toss", fields_);
}

RandomTracer::RandomTracer()
{
}

void RandomTracer::capture_state(AbstractRandom* obj)
{
    const QVariantMap &fields_ {
    };
    TraceClient::instance()->state("apigear.game.Random#_state", fields_);
    qDebug() << "state: " <<  "apigear.game" <<  "Random" << "_state" << fields_;
}
void RandomTracer::trace_generate(int min, int max)
{
    const QVariantMap &fields_ {
        { "min", QVariant::fromValue(min) },
        { "max", QVariant::fromValue(max) },

    };
    TraceClient::instance()->call("apigear.game.Random#generate", fields_);
}