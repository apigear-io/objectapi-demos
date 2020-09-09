from apigear_game.api import api
import random

class Random(api.IRandom):
    def __init__(self):
        pass

    def generate(self, min: int, max: int) -> int:
        return random.randint(min, max)