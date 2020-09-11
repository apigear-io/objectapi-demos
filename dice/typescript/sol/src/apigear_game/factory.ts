import { IDice, IRandom } from "./api";

import { Dice } from "./dice";

import { Random } from "./random";

export class Factory {
  createDice(): IDice {
    const rand = this.createRandom();
    return new Dice(rand);
  }
  createRandom(): IRandom {
    return new Random();
  }
}
