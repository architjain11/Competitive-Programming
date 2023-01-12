with open('Advent-Of-Code\Advent-Of-Code-2022\day3-data.txt', 'r') as f:
    rucksacks = [line.replace('\n', '') for line in f.readlines()]

def priority(item):
    if 'a' <= item <= 'z':
        return ord(item)-ord('a')+1
    else:
        return ord(item)-ord('A')+27

ans=0
for i in range(0, len(rucksacks), 3):
    group=rucksacks[i:i+3]
    shared=[
        item for item in group[0]
        if item in group[1] and item in group[2]    
    ][0]
    ans+=priority(shared)

print(ans)