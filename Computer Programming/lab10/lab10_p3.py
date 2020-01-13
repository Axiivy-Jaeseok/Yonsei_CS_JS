def countAllLetters(line):
    """ Counts letters in 'line' and returns result list. If the line
        does not contain any letter, returns an empty list.
        
        Note 1: the list of letters must be sorted alphabetically.
                (This is a requirement in addition to the textbook problem.)
        Note 2: your letters in the result-list must be stored in lower-case.
    """

# make string to lower
    line = line.lower()
    result = []

# define '0' list
    count = [0]*26

# increase the count when find the alphabet
    for i in range(0, len(line)):
        if line[i]>='a' and line[i] <= 'z':
            index = ord(line[i])-97
            count[index] = count[index] + 1

# make a result list
    for j in range(0, len(count)):
        if count[j] != 0:
            result.append((chr(97+j), count[j]))

    return result
            
