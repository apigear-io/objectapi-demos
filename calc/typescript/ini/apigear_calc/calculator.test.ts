import { Calculator } from "./calculator"

test('Calculator.add', () => {
  const obj = new Calculator()
  expect(typeof obj.add).toBe('function');
});

test('Calculator.substract', () => {
  const obj = new Calculator()
  expect(typeof obj.substract).toBe('function');
});

test('Calculator.multiply', () => {
  const obj = new Calculator()
  expect(typeof obj.multiply).toBe('function');
});

test('Calculator.divide', () => {
  const obj = new Calculator()
  expect(typeof obj.divide).toBe('function');
});

test('Calculator.clear', () => {
  const obj = new Calculator()
  expect(typeof obj.clear).toBe('function');
});