package calc

import "testing"

func TestCalculatorAdd(t *testing.T) {
	c := NewCalculator()
	if c.GetTotal() != 0 {
		t.Error("total must be 0")
	}
	c.Add(1)
	if c.GetTotal() != 1 {
		t.Error("total must be 1")
	}
}

func TestCalculatorSubstract(t *testing.T) {
	c := NewCalculator()
	if c.GetTotal() != 0 {
		t.Error("total must be 0")
	}
	c.Substract(1)
	if c.GetTotal() != -1 {
		t.Error("total must be -1")
	}
}

func TestCalculatorMultiply(t *testing.T) {
	c := NewCalculator()
	if c.GetTotal() != 0 {
		t.Error("total must be 0")
	}
	c.Add(2)
	c.Multiply(2)
	if c.GetTotal() != 4 {
		t.Error("total must be 4")
	}
}

func TestCalculatorDivide(t *testing.T) {
	c := NewCalculator()
	if c.GetTotal() != 0 {
		t.Error("total must be 0")
	}
	c.Add(4)
	c.Divide(2)
	if c.GetTotal() != 2 {
		t.Error("total must be 2")
	}
}

func TestCalculatorClear(t *testing.T) {
	c := NewCalculator()
	if c.GetTotal() != 0 {
		t.Error("total must be 0")
	}
	c.Add(4)
	c.Clear()
	if c.GetTotal() != 0 {
		t.Error("total must be 0")
	}
}
