import { IRandom } from "./api";
import * as api from "./api";

export class Dice implements api.IDice {
  value = 0;
  random: IRandom;
  constructor(random: IRandom) {
    this.random = random;
  }
  toss(): void {
    this.value = this.random.generate(1, 6);
  }
}
