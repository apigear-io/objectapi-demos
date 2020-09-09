
from apigear_game.dice import Dice

class TestDice:

    def test_toss(self):
        o = Dice()
        o.toss()
