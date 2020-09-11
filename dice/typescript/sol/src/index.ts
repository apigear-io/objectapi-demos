import { Random } from "./apigear_game/random";
import { Dice } from "./apigear_game/dice";
import * as readline from "readline";

const rand = new Random();
const dice = new Dice(rand);

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
  prompt: "$ ",
});

rl.prompt();

rl.on("line", (line) => {
  const args = line.trim().split(" ");
  const action = args[0];
  const num = parseInt(args[1]);

  switch (action) {
    case "exit":
      process.exit(0);
      break;
    case "toss":
      dice.toss();
      break;
  }
  console.log("value:", dice.value);
  rl.prompt();
}).on("close", () => {
  process.exit(0);
});
