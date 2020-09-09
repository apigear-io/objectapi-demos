package calc

import "testing"

func TestCalculatorAdd(t *testing.T) {
  c := NewCalculator()
  c.Add(0)
}

func TestCalculatorSubstract(t *testing.T) {
  c := NewCalculator()
  c.Substract(0)
}

func TestCalculatorMultiply(t *testing.T) {
  c := NewCalculator()
  c.Multiply(0)
}

func TestCalculatorDivide(t *testing.T) {
  c := NewCalculator()
  c.Divide(0)
}

func TestCalculatorClear(t *testing.T) {
  c := NewCalculator()
  c.Clear()
}
