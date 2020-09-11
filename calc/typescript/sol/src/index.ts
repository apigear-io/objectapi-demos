import { Calculator } from "./apigear_calc/calculator";
import * as readline from "readline";

const calc = new Calculator();

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
    case "add":
      calc.add(num);
      break;
    case "sub":
      calc.substract(num);
      break;
    case "mul":
      calc.multiply(num);
      break;
    case "div":
      calc.divide(num);
      break;
    case "clear":
      calc.clear();
  }
  console.log("total:", calc.total);
  rl.prompt();
}).on("close", () => {
  process.exit(0);
});
