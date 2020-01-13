# print the Introduction
print("This program can determine if a given string is a palindrome\n")
print("(Enter return to exit)")

# define flag
flag = True
while flag:

# user input
    pali = input("Enter string to check: ")
    if pali == '':
        flag = False
    else:

# determine whether the palidrom is
        pali_flag = True
        mid = len(pali)//2
        i = 0
        j = len(pali)-1
        if len(pali) % 2 == 1:
            while i<mid and j>mid:
                if pali[i] != pali[j]:
                    pali_flag = False
                i = i+1
                j = j-1
        else:
            while i<mid and j>=mid:
                if pali[i] != pali[j]:
                    pali_flag = False
                i = i+1
                j = j-1
            
# output
        if pali_flag == True:
            print(pali, "is a palindrome")
        else:
            print(pali, "is NOT a palindrome")
            
            

    
