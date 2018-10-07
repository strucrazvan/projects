class Square():
    def __init__(self):
        '''

        '''
        self.__grid=[['0','0','0','0','0','0','0','0'],
                     ['0', '0', '0', '0', '0', '0', '0', '0'],
                     ['0', '0', '0', '0', '0', '0', '0', '0'],
                     ['0', '0', '0', '0', '0', '0', '0', '0'],
                     ['0', '0', '0', '0', '0', '0', '0', '0'],
                     ['0', '0', '0', '0', '0', '0', '0', '0'],
                     ['0', '0', '0', '0', '0', '0', '0', '0'],
                     ['0', '0', '0', '0', '0', '0', '0', '0']]
    def __str__(self):
        return str(self.__grid)
    def getGrid(self):
        return self.__grid
    def setGrid(self,new):
        self.__grid=new
    def getElem(self,x,y):
        return self.__grid[x][y]
    def Trans(self):
        x=self.__grid.copy()
        for i in range(0,len(x)):
            for j in range(0,len(x)):
                pass

