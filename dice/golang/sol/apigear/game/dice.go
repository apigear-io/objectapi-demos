package game

import "project/apigear/game/api"

type dice struct {
	r api.Random
	v int
}

func NewDice(r api.Random) api.Dice {
	obj := dice{r: r}
	return &obj
}

func (d *dice) GetValue() int {
	return d.v
}

func (d *dice) SetValue(value int) {
	d.v = value
}

func (d *dice) Toss() {
	d.v = d.r.Generate(1, 6)
}
