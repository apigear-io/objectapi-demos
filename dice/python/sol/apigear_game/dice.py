from apigear_game.api import api

class Dice(api.IDice):
    def __init__(self, random: api.IRandom):
        self.random = random
        self.__value : int = 0

    @property
    def value(self):
        return self.__value

    def toss(self) -> None:
        self.__value = self.random.generate(1, 6)