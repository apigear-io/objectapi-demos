package calc

import "project/apigear/calc/api"

type calculator struct {
}

func NewCalculator() api.Calculator {
  obj := calculator{}
  return &obj
}

func (c *calculator) GetTotal() int {
  return 0
}

func (c *calculator) SetTotal(total int) {  
}

func (c *calculator) Add(a int)  {
  return 
}

func (c *calculator) Substract(a int)  {
  return 
}

func (c *calculator) Multiply(a int)  {
  return 
}

func (c *calculator) Divide(a int)  {
  return 
}

func (c *calculator) Clear()  {
  return 
}
