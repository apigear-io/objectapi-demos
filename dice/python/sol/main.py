import sys
from apigear_game.dice import Dice
from apigear_game.random import Random

def run():
  rand = Random()
  dice = Dice(random=rand)

  while True:
    line = input('$ ')
    args = line.split()
    action = args[0] if len(args) >= 1 else None
    if 'exit' == action:
      sys.exit(0)
    elif 'toss' == action:
      dice.toss()
      print('value:', dice.value)

if __name__ == '__main__':
  run()

  