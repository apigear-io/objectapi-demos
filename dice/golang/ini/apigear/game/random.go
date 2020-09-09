package game

import "project/apigear/game/api"

type random struct {
}

func NewRandom() api.Random {
  obj := random{}
  return &obj
}

func (r *random) Generate(min int, max int) int {
  return 0
}
