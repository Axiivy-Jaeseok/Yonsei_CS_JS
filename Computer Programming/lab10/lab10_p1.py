def countLetters(line):
    """ Count all letter characters in string ``line'' and write the
        result to file ``answer.txt''.
        The number of letter characters must be written to the file:
        countLetters('abA1 23') -> writes 3
        countLetters('!') -> writes 0
    """
    count = 0
    myfile = open('answer.txt', 'w')
    for i in range(0, len(line)):
        if line[i] >= 'a' and line[i] <= 'z':
            count = count + 1
        elif line[i] >= 'A' and line[i] <= 'Z':
            count = count + 1
    myfile.write(str(count) + '\n')
    myfile.close()
