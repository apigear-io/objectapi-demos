from apigear_game.api import api

class Dice(api.IDice):
    def __init__(self):
        self.__value : int = 0

    @property
    def value(self):
        return self.__value

    def toss(self) -> None:
        return 