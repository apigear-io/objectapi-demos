
from apigear_game.dice import Dice
from apigear_game.api import api

class MockRandom(api.IRandom):
    def __init__(self):
        self.count = 0

    def generate(self, min, max):
        self.count += 1
        return min

class TestDice:

    def test_toss(self):
        r = MockRandom()
        d = Dice(r)
        assert r.count == 0
        d.toss()
        assert r.count == 1
        assert d.value >= 1 and d.value <= 6
