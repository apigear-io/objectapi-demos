

export interface IDice {  
  value: number

  toss(): void
}

export interface IRandom {

  generate(min: number, max: number): number
}

export interface IFactory {  
  createDice() : IDice  
  createRandom() : IRandom
}
