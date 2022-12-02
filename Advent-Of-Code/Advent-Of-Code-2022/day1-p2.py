f=open('Advent-Of-Code-2022\day1-data.txt')
calsList=list()
cals=0
for num in f:
    if num=='\n':
        calsList.append(cals)
        cals=0
    else:
        cals+=int(num)
calsList.sort()
print(calsList[-1]+calsList[-2]+calsList[-3])