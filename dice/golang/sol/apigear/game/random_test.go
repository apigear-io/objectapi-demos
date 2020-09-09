package game

import "testing"

func TestRandomGenerate(t *testing.T) {
	r := NewRandom()
	for i := 0; i < 10; i++ {
		v := r.Generate(1, 6)
		if v < 1 || v >= 6 {
			t.Errorf("%d value outside [0.0,1.0)", v)
		}
	}
}
