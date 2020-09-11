

export interface ICalculator {  
  total: number

  add(a: number): void

  substract(a: number): void

  multiply(a: number): void

  divide(a: number): void

  clear(): void
}

export interface IFactory {  
  createCalculator() : ICalculator
}
