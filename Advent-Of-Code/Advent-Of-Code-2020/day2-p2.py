f = open("Advent Of Code/2020/day2-data.txt")
correct = 0
for line in f:
    position = 0
    s = line.split()
    a = s[0].split('-')
    if s[2][int(a[0])-1]==s[1][0]: position+=1
    if s[2][int(a[1])-1]==s[1][0]: position+=1
    if position == 1: correct+=1
print(correct)