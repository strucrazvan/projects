import copy


class Controller():
    def __init__(self,sqr):
        self.__sqr=sqr

    def printSquare(self):
        '''

        :return:
        '''
        for i in self.__sqr.getGrid():
            print(i)

    def block(self,x,y):
        '''

        :param x:
        :param y:
        :return:
        '''
        if x>7 or y>7 or x<0 or y<0:
            return False
        a=self.__sqr.getGrid()

        if a[x][y]=='X'or a[x][y+1]=='X' or a[x+1][y+1]=='X' or a[x+1][y]=='X':
            return False
        a[x][y]='X'
        a[x][y+1]='X'
        a[x+1][y+1]='X'
        a[x+1][y]='X'
        return True
    def getSquare(self):
        '''

        :return:
        '''
        return self.__sqr.getGrid()
    def tub(self, x, y):
        '''

        :param x:
        :param y:
        :return:
        '''
        if x > 7 or y > 7 or x < 0 or y < 0:
            return False

        a = self.__sqr.getGrid()
        if  a[x][y+1] == 'X' or a[x+1][y] == 'X'or a[x + 2][y + 1] == 'X' or a[x + 1][y+2] == 'X':
            return False

        a[x][y+1] = 'X'
        a[x+1][y] = 'X'
        a[x + 2][y + 1] = 'X'
        a[x + 1][y+2] = 'X'
        return True
    def Generation(self):
        '''

        :return:
        '''
        a= [[0, 0, 0 ,  0 ,  0 ,  0 ,  0 ,  0 ],
            [ 0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ],
            [ 0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ],
            [ 0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ],
            [ 0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ],
            [ 0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ],
            [ 0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ],
            [ 0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ]]

        y=copy.deepcopy(self.__sqr.getGrid())
        x=self.__sqr.getGrid()
        for i in range(0,8):
            y[i].append(0)
            y.append([0,0,0,0,0,0,0,0,0])


        for i in range(0,8):
            for j in range(0,8):
                if(y[i][j-1]=='X'):
                    a[i][j]+=1
                if y[i][j+1]=='X':
                    a[i][j]+=1
                if y[i + 1][j] == 'X':
                    a[i][j]+=1
                if y[i - 1][j] == 'X':
                    a[i][j]+=1

                if y[i-1][j-1] == 'X':
                    a[i][j]+=1
                if y[i-1][j+1] == 'X':
                    a[i][j]+=1
                if y[i + 1][j-1] == 'X':
                    a[i][j]+=1
                if y[i+1][j+1] == 'X':
                    a[i][j]+=1
        for i in range(0,8):
            for j in range(0,8):
                if(x[i][j]=='X' and a[i][j]<2):
                    x[i][j]='0'
                if (x[i][j] == 'X' and a[i][j] >= 2 and a[i][j]<=3):
                    x[i][j] = 'X'
                if(x[i][j] == 'X' and a[i][j] >= 4):
                    x[i][j] = '0'
                if(x[i][j]=='0' and a[i][j]==3):
                    x[i][j]='X'

