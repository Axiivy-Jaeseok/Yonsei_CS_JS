# user input
frac = input("Enter a fraction: ")

# set the fds(first digits starts)
fds = 0
while frac[fds] == ' ':
    fds += 1

# set the fde(first digits ends)
fde = fds
while (frac[fde] != ' ' and frac[fde] != '/'):
    fde += 1

# set the slash index
sla = frac.index('/')

# set the sds(second digits starts)
sds = sla+1
while frac[sds] == ' ':
    sds += 1

# set the sde(second digits ends)
sde = sds
while (frac[sde] != ' ' and (sde+1)!=len(frac)):
    sde += 1

# set the first num and second num
fd = int(frac[fds:fde])
sd = int(frac[sds:sde+1])

# find which is larger
if fd>sd :
    lar_num = fd
    sma_num = sd
else :
    sma_num = fd
    lar_num = sd

# algorithm for finding GCD
R = lar_num%sma_num
while R != 0:
    lar_num = sma_num
    sma_num = R
    R = lar_num%sma_num
GCD = sma_num

# output
print("In lowest terms: "+str(fd//GCD)+'/'+str(sd//GCD))
