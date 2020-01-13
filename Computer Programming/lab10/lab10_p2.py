def copyFiles(f1, f2, f3):
    
    """ Copies f1 and f2 onto f3.

        The function assumes that files f1 and f2 can be opened, and that
        no error occurs in writing file f3.
        Therefore, the function will always return 0.
        (Error handling with file I/O will be part of next week's lecture.)
    """

# define file Input
    in1 = open(f1, 'r')
    in2 = open(f2, 'r')
    out = open(f3, 'w')

# read and write the string on input 1
    line = in1.readline()
    while line != '':
        out.write(line)
        line = in1.readline()

# read and wrtie the string on input 2
    line = in2.readline()
    while line != '':
        out.write(line)
        line = in2.readline()

    in1.close()
    in2.close()
    out.close()

    return 0

