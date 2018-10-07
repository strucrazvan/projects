from domain.square import Square
from controller.squareController import Controller
from ui.ui import ui
from tests import MyTestCase
sqr=Square()
Test = MyTestCase()
Test.do_tests()
a=Controller(sqr)
cons=ui(a,"data/Pattern.txt","data/configuration.txt")
cons.run()
