import * as api from "./api";

export class Random implements api.IRandom {
  generate(min: number, max: number): number {
    return Math.floor(Math.random() * (max - min + 1) + min);
  }
}
