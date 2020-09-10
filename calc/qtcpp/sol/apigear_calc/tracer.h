#pragma once

#include <QtCore>

#include "api.h"


class CalculatorTracer
{
public:
  CalculatorTracer();
  static void capture_state(AbstractCalculator* obj);
  static void trace_add(int a);
  static void trace_substract(int a);
  static void trace_multiply(int a);
  static void trace_divide(int a);
  static void trace_clear();
};