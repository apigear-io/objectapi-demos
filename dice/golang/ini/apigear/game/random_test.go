package game

import "testing"

func TestRandomGenerate(t *testing.T) {
  r := NewRandom()
  r.Generate(0,0)
}
