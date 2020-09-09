package main

import (
	"bufio"
	"fmt"
	"math/rand"
	"os"
	"project/apigear/game"
	"strings"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	scanner := bufio.NewScanner(os.Stdin)
	// create a random generator
	r := game.NewRandom()
	// pass random API to dice
	dice := game.NewDice(r)
	for {
		fmt.Print("$ ")
		scanner.Scan()
		words := strings.Fields(scanner.Text())
		if len(words) == 0 {
			continue
		}
		action := words[0]
		switch action {
		case "exit":
			os.Exit(0)
		case "toss":
			dice.Toss()
			fmt.Println("value: ", dice.GetValue())
		}
	}
}
