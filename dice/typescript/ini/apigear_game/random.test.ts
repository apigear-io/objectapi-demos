import { Random } from "./random"

test('Random.generate', () => {
  const obj = new Random()
  expect(typeof obj.generate).toBe('function');
});