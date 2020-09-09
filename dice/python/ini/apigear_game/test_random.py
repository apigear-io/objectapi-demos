
from apigear_game.random import Random

class TestRandom:

    def test_generate(self):
        o = Random()
        for i in range(10):
            v = o.generate()
