import {  
  IDice,  
  IRandom
} from './api'

import { Dice } from './dice'

import { Random } from './random'

export class Factory {  
  createDice() : IDice {
    return new Dice()
  }  
  createRandom() : IRandom {
    return new Random()
  }
}