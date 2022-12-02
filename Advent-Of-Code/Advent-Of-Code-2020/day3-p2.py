f = open("Advent Of Code/2020/day3-data.txt")
ans=1
x,trees = 0,0
for line in f:
    counter = len(line.rstrip('\n'))
    if line[x] == '#':
        trees+=1
    x = (x+1)%counter
if trees != 0: ans*=trees

f.seek(0,0)
x,trees = 0,0
for line in f:
    counter = len(line.rstrip('\n'))
    if line[x] == '#':
        trees+=1
    x = (x+3)%counter
if trees != 0: ans*=trees

f.seek(0,0)
x,trees = 0,0
for line in f:
    counter = len(line.rstrip('\n'))
    if line[x] == '#':
        trees+=1
    x = (x+5)%counter
if trees != 0: ans*=trees

f.seek(0,0)
x,trees = 0,0
for line in f:
    counter = len(line.rstrip('\n'))
    if line[x] == '#':
        trees+=1
    x = (x+7)%counter
if trees != 0: ans*=trees

f.seek(0,0)
x,trees,flag = 0,0,0
for line in f:
    if flag == 1: 
        flag=0
        continue
    else:
        counter = len(line.rstrip('\n'))
        if line[x] == '#':
            trees+=1
        x = (x+1)%counter
        flag=1
if trees != 0: ans*=trees

print(ans)