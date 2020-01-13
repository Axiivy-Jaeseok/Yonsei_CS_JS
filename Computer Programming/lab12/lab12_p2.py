def moderateDays(mydict):
    '''Returns a list [...] of the days for which the average
       temperature was between 70 and 79 degrees.
    '''

    output_list = []
    for day in mydict.keys():
        if mydict[day] >= 70 and mydict[day] <= 79:
            output_list.append(day)

    return output_list
            
