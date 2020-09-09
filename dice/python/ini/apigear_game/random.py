from apigear_game.api import api

class Random(api.IRandom):
    def __init__(self):
        pass

    def generate(self, min: int, max: int) -> int:
        return 0