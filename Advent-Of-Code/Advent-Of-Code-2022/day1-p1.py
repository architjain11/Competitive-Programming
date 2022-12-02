f=open("Advent-Of-Code-2022\day1-data.txt")
maxim=float('-inf')
cals=0
for num in f:
    if num=='\n':
        maxim=max(cals, maxim)
        cals=0
    else:
        cals+=int(num)
print(maxim)