class ui():
    def __init__(self,contr,PatternFile,File):
        self.__contr=contr
        self.__PatternFile = PatternFile
        self.__File=File
        self.__patterns = []

    def validate_type(self, x, type, message):
        '''
        This validates the type
        :param x:
        :param type:
        :param message:
        :return:
        '''
        try:
            x = type(x)
            return True
        except:
            print(message)
            return False
    def readCommand(self):
        '''

        :return:
        '''
        cmd = input("Command: ")
        if cmd.find(" ") == -1:
            command = cmd
            params = ""
        else:
            command = cmd[0:cmd.find(" ")]
            params = cmd[cmd.find(" "):]
            params = params.split(" ")

            for i in range(0, len(params)):
                params[i] = params[i].strip()
        return command, params

    def readPatterns(self):
        '''

        :return:
        '''
        with open(self.__PatternFile) as f:
            for line in f:
                args = line.split(",")
            self.__patterns=args
        print(self.__patterns)
    def block(self,x,y):
        '''

        :param x:
        :param y:
        :return:
        '''
        if not self.__contr.block(int(x),int(y)):
            print("Incorect coords or it is already something alive there")

    def tub(self, x, y):
        '''

        :param x:
        :param y:
        :return:
        '''
        if not self.__contr.tub(int(x), int(y)):
            print("Incorect coords or it is already something alive there")
    def generation(self,x):
        '''

        :param x:
        :return:
        '''
        if x==0:
            print("Current generation: ")
            self.__contr.printSquare()
        else:
            for i in range(0,x):
                self.__contr.Generation()
                print("Generation "+str(i+1))
                self.__contr.printSquare()
    def save(self,filename):
        '''

        :return:
        '''
        with open(filename, "w") as f:
            x=self.__contr.getSquare()
            for i in range(0, 8):
                for j in range(0, 8):
                    f.write(x[i][j]+" ")
    def load(self,filename):
        with open(filename) as f:
            for line in f:
                args = line.split(" ")
                cont=0
                x=self.__contr.getSquare()
                for i in range(0,8):
                    for j in range(0,8):
                        x[i][j]=args[cont]
                        cont+=1

    def run(self):
        '''
        runs
        :return:
        '''
        self.__contr.printSquare()
        self.readPatterns()
        commands = {'place','tick','save'}
        cmd = ""
        while (cmd != "Stop"):
            cmd, params = self.readCommand()
            if cmd == 'save':
                self.save(params[1])
            elif cmd=='load':
                self.load(params[1])

            else:
                if cmd in commands and len(params)>0:

                    if params[1] in self.__patterns:
                        if self.validate_type(params[2],int,"TYPE eRR") and self.validate_type(params[3],int,"TYPE eRR"):
                            if(params[1]=='block'):
                                self.block(params[2],params[3])
                            if (params[1] == 'tub'):
                                self.tub(params[2], params[3])

                    else:
                        if len(params) == 2:
                            if self.validate_type(params[1],int,"TYPE eRR"):
                                self.generation(int(params[1]))
                else:
                    print("Not a valid command")