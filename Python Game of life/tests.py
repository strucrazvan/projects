import unittest
from domain.square import Square
from controller.squareController import Controller


class MyTestCase(unittest.TestCase):
    def do_tests(self):
        x = Square()
        y = x.getElem(1, 1)
        self.assertEqual(y, '0', "FATAL ERROR")
        x = Square()
        y = x.getElem(0, 0)
        self.assertEqual(y, '0', "FATAL ERROR")
        y = x.getElem(5, 5)
        self.assertEqual(y, '0', "FATAL ERROR")

        contr = Controller(x)
        contr.block(0, 0)
        y = x.getElem(2, 2)
        self.assertEqual(y, '0', "FATAL ERROR")
        y = x.getElem(0, 0)
        self.assertEqual(y, 'X', "FATAL ERROR")


if __name__ == '__main__':
    unittest.main()
