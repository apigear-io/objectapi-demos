import { Calculator } from "./calculator";

test("Calculator.add", () => {
  const obj = new Calculator();
  expect(obj.total).toBe(0);
  obj.add(4);
  expect(obj.total).toBe(4);
});

test("Calculator.substract", () => {
  const obj = new Calculator();
  expect(obj.total).toBe(0);
  obj.substract(4);
  expect(obj.total).toBe(-4);
});

test("Calculator.multiply", () => {
  const obj = new Calculator();
  expect(obj.total).toBe(0);
  obj.add(2);
  obj.multiply(2);
  expect(obj.total).toBe(4);
});

test("Calculator.divide", () => {
  const obj = new Calculator();
  expect(obj.total).toBe(0);
  obj.add(4);
  obj.divide(2);
  expect(obj.total).toBe(2);
});

test("Calculator.clear", () => {
  const obj = new Calculator();
  expect(obj.total).toBe(0);
  obj.add(4);
  obj.clear();
  expect(obj.total).toBe(0);
});
