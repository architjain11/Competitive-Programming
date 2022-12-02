f = open("Advent Of Code/2020/day4-data.txt")
valid,count = 0,0
for line in f:
    if line[0] == '\n':count=0
    else:
        if 'iyr:' in line: count+=1
        if 'byr:' in line: count+=1
        if 'eyr:' in line: count+=1
        if 'hgt:' in line: count+=1
        if 'hcl:' in line: count+=1
        if 'ecl:' in line: count+=1
        if 'pid:' in line: count+=1
    if count == 7:
        valid+=1
        count=0 #so that one passport is not counted valid as multiple times because the condition count===7 check is done on every line
print(valid)