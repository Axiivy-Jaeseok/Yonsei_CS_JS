count = 0
L = input("Enter a sentence: ")
for i in L:
    if i=='a' or i=='e' or i == 'i' or i == 'o' or i=='u'or i=='A' or i=='E' or i=='O' or i=='U' or i=='I':
        count = count + 1

if count == 1:
    print("Your sentence contains 1 vowel.")
else:
    print("Your sentence contains %d vowels." % count)
