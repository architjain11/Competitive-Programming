f = open("Advent Of Code/2020/day5-data.txt")
a = list()
max=0
min=2000
for line in f:
    line=line.rstrip('\n')
    lower, upper = 0, 127 #this is for rows
    low, up = 0, 7 #this is for columns
    for i in range(len(line)):
        if i<7:
            if line[i]=='F':
                upper -= -(-(upper-lower)//2)
            elif line[i]=='B':
                lower += -(-(upper-lower)//2)
        else:
            if line[i]=='L':
                up -= -(-(up-low)//2)
            elif line[i]=='R':
                low += -(-(up-low)//2)
    seat_ID = lower*8 + low
    a.append(seat_ID)
    if seat_ID>max: max=seat_ID
    if seat_ID<min: min=seat_ID
a.sort()
b = list(range(min, max+1))
for i in range(len(a)):
    if a[i]!=b[i]: 
        print(b[i])
        break