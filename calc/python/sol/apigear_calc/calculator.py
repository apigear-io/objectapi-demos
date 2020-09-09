from apigear_calc.api import api

class Calculator(api.ICalculator):
    def __init__(self):
        self.__total : int = 0

    @property
    def total(self):
        return self.__total

    def add(self, a: int) -> None:
        self.__total += a

    def substract(self, a: int) -> None:
        self.__total -= a

    def multiply(self, a: int) -> None:
        self.__total *= a

    def divide(self, a: int) -> None:
        self.__total /= a

    def clear(self) -> None:
        self.__total = 0
