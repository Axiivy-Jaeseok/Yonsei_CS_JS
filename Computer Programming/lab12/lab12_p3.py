import random
import sys

inp_name = input("Enter a filename: ")
ch_list = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
           'l', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
           'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6',
           '7', '8', '9', ' ']

en_li_flag = True
try:
    inp_file = open(inp_name, 'r')

except:
    sys.exit()

inde = inp_name.index('.')
f_name = inp_name[:inde]

if '.txt' in inp_name:
    while en_li_flag:
        en_li_flag = False
        en_list = list(ch_list)
        random.shuffle(en_list)
        for i in range(len(ch_list)):
            if en_list[i] == ch_list[i]:
                en_li_flag = True

    key_file = open(f_name+'.key', 'w')
    for j in range(len(ch_list)):
        key_file.write(ch_list[j]+','+en_list[j]+'\n')

    en_file = open(f_name+'.enc', 'w')

    line = inp_file.readline()
    while line != '':
        en_line = ''
        for i in range(len(line)):
            if line[i] == '\n':
                en_line = en_line+'\n'
            for j in range(len(ch_list)):
                if line[i] == ch_list[j]:
                    en_line = en_line+en_list[j]
                elif line[i].upper == ch_list[j]:
                    en_line = en_line+en_list[j].lower
        en_file.write(en_line)
        line = inp_file.readline()

elif '.enc' in inp_name:
    key_file = open(f_name+'.key', 'r')
    key_dic = dict()
    key_line = key_file.readline()
    while key_line != '':
        key_dic[key_line[2]] = key_line[0]
        key_line = key_file.readline()
    print(key_dic)
