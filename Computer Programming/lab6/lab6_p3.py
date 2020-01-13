# import sys
import sys

dig_flag = False
cha_flag = False
alp_flag = False

# define the tuple and case changer
password_out = ''
encryption_key = (('a','m'), ('b','h'), ('c','t'), ('d','f'), ('e','g'),
  ('f','k'), ('g','b'), ('h','p'), ('i','j'), ('j','w'), ('k','e'),('l','r'),
  ('m','q'), ('n','s'), ('o','l'), ('p','n'), ('q','i'), ('r','u'), ('s','o'),
  ('t','x'), ('u','z'), ('v','y'), ('w','v'), ('x','d'), ('y','c'), ('z','a'),
  ('#', '!'), ('@', '('), ('%', ')'))
    
# user input password
password_in = input('Enter password: ')

letter_found = False

case_changer = ord('a') - ord('A')
    
for ch in password_in:
    
    for t in encryption_key:

# when input character is 'a' to 'z'
        if ('a' <= ch and ch <= 'z') and ch == t[0]:  
            password_out = password_out + t[1]
            alp_flag = True
            letter_found = True

# when input character is 'A' to 'Z'
        elif ('A' <= ch and ch <= 'Z') and chr(ord(ch) + 32) == t[0]:
            password_out = password_out + chr(ord(t[1]) - case_changer)
            alp_flag = True
            letter_found = True

# when input character is '#' or '@' or '%'            
        elif (ch == '#' and ch == t[0]) or (ch == '@' and ch == t[0]) or (ch == '%' and ch == t[0]):
            password_out = password_out + t[1]
            cha_flag = True
            letter_found = True

# when input number            
    if ch >= '0' and ch <= '9':
        password_out = password_out + ch
        dig_flag = True
        letter_found = True

# when invalid input
    if not letter_found:
            print("Invalid password!")
            sys.exit()


if not(dig_flag and alp_flag and cha_flag):
    print("Invalid password!")
    sys.exit()

# output
print('Your encrypted password is:', password_out)
