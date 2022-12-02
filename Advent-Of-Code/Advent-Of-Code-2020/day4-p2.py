f = open("Advent Of Code/2020/day4-data.txt")
valid,count = 0,0
fields = ['byr', 'eyr', 'iyr', 'hgt', 'hcl', 'ecl', 'pid']
for line in f:
    if line[0] == '\n':
        count=0
        continue
    for field in line.split():
        key, value = field.split(':')
        if key in fields:
            if key == 'byr':
                if int(value)>=1920 and int(value)<=2002: count+=1
            if key == 'iyr':
                if int(value)>=2010 and int(value)<=2020: count+=1
            if key == 'eyr':
                if int(value)>=2020 and int(value)<=2030: count+=1
            if key == 'hgt':
                if value[-2:] == 'cm':
                    if int(value[:-2])>=150 and int(value[:-2])<=193: count+=1
                elif value[-2:] == 'in':
                    if int(value[:-2])>=59 and int(value[:-2])<=76: count+=1
            if key == 'hcl':
                if value[0] == '#':
                    if len(value) == 7:
                        flag=0
                        for ele in value:
                            if flag==0:
                                flag+=1
                                continue
                            else:
                                if ele.isdigit():
                                    if int(ele)>=0 and int(ele)<=9: flag+=1
                                elif ele>='a' and ele<='f': flag+=1
                        if flag==7: 
                            count+=1
            if key == 'ecl':
                colors = ['amb', 'blu', 'brn', 'gry', 'grn', 'hzl', 'oth']
                if value in colors: count+=1
            if key == 'pid':
                if len(value)==9: count+=1
    if count == 7:
        valid+=1
        count=0 #so that one passport is not counted valid as multiple times because the condition count===7 check is done on every line
print(valid)