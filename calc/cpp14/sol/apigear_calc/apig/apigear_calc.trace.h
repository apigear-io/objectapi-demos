#pragma once

#include "apigear_calc.apig.h"


class CalculatorTracer
{
public:
  CalculatorTracer();
  static void capture_state(CalculatorBase* obj);
  static void trace_add(int a);
  static void trace_substract(int a);
  static void trace_multiply(int a);
  static void trace_divide(int a);
  static void trace_clear();
};
