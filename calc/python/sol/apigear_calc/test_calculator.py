from apigear_calc.calculator import Calculator

class TestCalculator:
    def test_add(self):
      calc = Calculator()
      assert calc.total == 0
      calc.add(2)
      assert calc.total == 2


    def test_substract(self):
      calc = Calculator()
      assert calc.total == 0
      calc.substract(2)
      assert calc.total == -2

    def test_multiply(self):
      calc = Calculator()
      assert calc.total == 0
      calc.add(2)
      calc.multiply(2)
      assert calc.total == 4

    def test_divide(self):
      calc = Calculator()
      assert calc.total == 0
      calc.add(4)
      calc.divide(2)
      assert calc.total == 2

    def test_clear(self):
      calc = Calculator()
      assert calc.total == 0
      calc.add(4)
      calc.clear()
      assert calc.total == 0
