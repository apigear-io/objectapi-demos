from apigear_calc.api import api

class Calculator(api.ICalculator):
    def __init__(self):
        self.__total : int = 0

    @property
    def total(self):
        return self.__total

    def add(self, a: int) -> None:
        return None

    def substract(self, a: int) -> None:
        return None

    def multiply(self, a: int) -> None:
        return None

    def divide(self, a: int) -> None:
        return None

    def clear(self) -> None:
        return None