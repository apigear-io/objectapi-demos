import { IRandom } from "./api";
import { Dice } from "./dice";

class MockRandom implements IRandom {
  count = 0;
  generate(min: number, max: number): number {
    this.count++;
    return min;
  }
}

test("Dice.toss", () => {
  const rand = new MockRandom();
  const dice = new Dice(rand);
  expect(rand.count).toBe(0);
  dice.toss();
  expect(rand.count).toBe(1);
});
