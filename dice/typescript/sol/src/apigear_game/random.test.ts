import { Random } from "./random";

test("Random.generate", () => {
  const rand = new Random();
  for (var i = 0; i < 10; i++) {
    const v = rand.generate(1, 6);
    expect(v).toBeGreaterThanOrEqual(1);
    expect(v).toBeLessThanOrEqual(6);
  }
});
