package api

type Dice interface {
    GetValue() int
    SetValue(value int)
    Toss() 
}

type Random interface {
    Generate(min int, max int) int
}
