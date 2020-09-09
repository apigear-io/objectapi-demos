import sys
from apigear_calc.calculator import Calculator

def run():

  calc = Calculator()

  while True:
    line = input('$ ')
    args = line.split()
    action = args[0] if len(args) >= 1 else None
    num = int(args[1]) if len(args) == 2 else 0
    if 'exit' == action:
      sys.exit(0)
    elif 'add' == action:
      calc.add(num)
    elif 'mul' == action:
      calc.multiply(num)
    elif 'sub' == action:
      calc.substract(num)
    elif 'div' == action:
      calc.divide(num)
    print('total:', calc.total)

if __name__ == '__main__':
  run()

  