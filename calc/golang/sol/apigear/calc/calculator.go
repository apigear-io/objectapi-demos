package calc

import "project/apigear/calc/api"

type calculator struct {
	v int
}

func NewCalculator() api.Calculator {
	obj := calculator{}
	return &obj
}

func (c *calculator) GetTotal() int {
	return c.v
}

func (c *calculator) SetTotal(total int) {
	c.v = total
}

func (c *calculator) Add(a int) {
	c.v += a
}

func (c *calculator) Substract(a int) {
	c.v -= a
}

func (c *calculator) Multiply(a int) {
	c.v *= a
}

func (c *calculator) Divide(a int) {
	c.v /= a
}

func (c *calculator) Clear() {
	c.v = 0
}
