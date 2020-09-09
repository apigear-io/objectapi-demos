package game

import "project/apigear/game/api"

type dice struct {
}

func NewDice() api.Dice {
  obj := dice{}
  return &obj
}

func (d *dice) GetValue() int {
  return 0
}

func (d *dice) SetValue(value int) {  
}

func (d *dice) Toss()  {
  return 
}
