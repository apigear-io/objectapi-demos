#pragma once

#include <QtCore>

#include "api.h"


class DiceTracer
{
public:
  DiceTracer();
  static void capture_state(AbstractDice* obj);
  static void trace_toss();
};


class RandomTracer
{
public:
  RandomTracer();
  static void capture_state(AbstractRandom* obj);
  static void trace_generate(int min, int max);
};