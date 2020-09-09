package game

import "testing"

type randomMock struct {
	count int
}

func (d *randomMock) Generate(min int, max int) int {
	d.count++
	return min
}

func TestDiceToss(t *testing.T) {
	r := randomMock{0}
	d := NewDice(&r)
	if r.count != 0 {
		t.Fail()
	}
	d.Toss()
	if r.count != 1 {
		t.Fail()
	}
}
