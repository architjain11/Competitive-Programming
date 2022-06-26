f = open("Advent Of Code/2020/day3-data.txt")
x,trees = 0,0
for line in f:
    counter = len(line.rstrip('\n'))
    if line[x] == '#':
        trees+=1
    x = (x+3)%counter
print(trees)