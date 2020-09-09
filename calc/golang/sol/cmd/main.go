package main

import (
	"bufio"
	"fmt"
	"math/rand"
	"os"
	"project/apigear/calc"
	"strconv"
	"strings"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	scanner := bufio.NewScanner(os.Stdin)
	// create a random generator
	c := calc.NewCalculator()
	for {
		fmt.Println("total: ", c.GetTotal())
		fmt.Print("$ ")
		scanner.Scan()
		words := strings.Fields(scanner.Text())
		if len(words) == 0 {
			continue
		}
		action := words[0]
		args := words[1:len(words)]
		numOk := false
		num := 0
		if len(args) == 1 {
			if v, err := strconv.Atoi(args[0]); err == nil {
				numOk = true
				num = v
			}
		}
		switch action {
		case "exit":
			os.Exit(0)
		case "add":
			if numOk {
				c.Add(num)
			}
		case "mul":
			if numOk {
				c.Multiply(num)
			}
		case "div":
			if numOk {
				c.Divide(num)
			}
		case "sub":
			if numOk {
				c.Substract(num)
			}
		case "clear":
			c.Clear()
		}
	}
}
