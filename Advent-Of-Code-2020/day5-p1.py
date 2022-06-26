f = open("Advent Of Code/2020/day5-data.txt")
max=0
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
    if seat_ID>max: max=seat_ID
print(max)