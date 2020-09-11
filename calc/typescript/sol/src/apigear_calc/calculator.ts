import * as api from "./api";

export class Calculator implements api.ICalculator {
  total = 0;
  add(a: number): void {
    this.total += a;
  }
  substract(a: number): void {
    this.total -= a;
  }
  multiply(a: number): void {
    this.total *= a;
  }
  divide(a: number): void {
    this.total /= a;
  }
  clear(): void {
    this.total = 0;
  }
}
