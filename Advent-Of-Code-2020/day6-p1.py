f = open("Advent Of Code/2020/day6-data.txt")
a=list()
ans=0
for line in f:
    if line == '\n': 
        ans+=len(a) 
        a.clear()
        continue
    line=line.rstrip('\n')
    for ele in line:
        if ele not in a: a.append(ele)
ans+=len(a)
print(ans)