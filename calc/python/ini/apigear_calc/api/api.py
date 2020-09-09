from typing import Iterable
from enum import Enum

class ICalculator:
    @property
    def total(self):
        raise NotImplementedError

    def add(self, a: int):
        raise NotImplementedError

    def substract(self, a: int):
        raise NotImplementedError

    def multiply(self, a: int):
        raise NotImplementedError

    def divide(self, a: int):
        raise NotImplementedError

    def clear(self):
        raise NotImplementedError
