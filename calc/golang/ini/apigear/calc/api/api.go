package api

type Calculator interface {
    GetTotal() int
    SetTotal(total int)
    Add(a int) 
    Substract(a int) 
    Multiply(a int) 
    Divide(a int) 
    Clear() 
}
