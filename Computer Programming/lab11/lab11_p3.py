def copyFiles(f1, f2, f3):
    
    """  Copies files f1 and f2 onto file f3.

         If f1, f2 or f3 cannot be opened, -1 is returned.
         Otherwise, the copy operation is performed and 0 is returned.
    """
    try: 
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

    except IOError:
        return -1
