class AvgList(list):

    def computeAvg(self):
        '''Computes the average of a list of numeric types.
           Raises the ValueError exception if a list element is neither
           an 'int' nor a 'float' object.
        '''

        # determine that the type is correct
        for i in self:
            if type(i)!=int and type(i)!=float:
                raise ValueError

        # calculate the average
        avg = sum(self)/len(self)

        return avg

