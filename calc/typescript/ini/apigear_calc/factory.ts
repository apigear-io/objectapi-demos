import {  
  ICalculator
} from './api'

import { Calculator } from './calculator'

export class Factory {  
  createCalculator() : ICalculator {
    return new Calculator()
  }
}