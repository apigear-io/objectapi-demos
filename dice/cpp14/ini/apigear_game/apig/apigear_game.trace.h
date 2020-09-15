#pragma once

#include "apigear_game.apig.h"


class DiceTracer
{
public:
  DiceTracer();
  static void capture_state(DiceBase* obj);
  static void trace_toss();
};


class RandomTracer
{
public:
  RandomTracer();
  static void capture_state(RandomBase* obj);
  static void trace_generate(int min, int max);
};
