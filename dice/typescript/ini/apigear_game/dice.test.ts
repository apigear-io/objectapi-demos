import { Dice } from "./dice"

test('Dice.toss', () => {
  const obj = new Dice()
  expect(typeof obj.toss).toBe('function');
});