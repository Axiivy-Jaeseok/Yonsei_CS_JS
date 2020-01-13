# define flag
flag = True

# define list of words
word_list = []

# user input word
while flag:
    word = input("Enter a word (q to quit): ")

# when user input 'q'
    if word == 'q':
        flag = False

# when first letter of word appears other site of words, append to list
    else:
        if (word[0].lower() in word[1:]) or (word[0].upper() in word[1:]):
            word_list.append(word)

# list sort
word_list.sort()

# output
print('[', end='')
for i in range(0, len(word_list)-1):
    print(word_list[i], end=', ')
print(word_list[len(word_list)-1]+']')
