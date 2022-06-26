f = open("Advent Of Code/2020/day6-data.txt")
a=list()
ans, people = 0,0
for line in f: 
    if line == '\n': 
        
        
        people=0
        a.clear()
        break
        # continue
    line=line.rstrip('\n')
    for ele in line:
        a.append(ele)
    people+=1
print(ans)