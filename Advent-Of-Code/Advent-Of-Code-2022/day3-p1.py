with open('Advent-Of-Code\Advent-Of-Code-2022\day3-data.txt', 'r') as f:
    rucksacks = [line.replace('\n', '') for line in f.readlines()]

def priority(item):
    if 'a' <= item <= 'z':
        return ord(item)-ord('a')+1
    else:
        return ord(item)-ord('A')+27

ans = 0
for rucksack in rucksacks:
    mid = len(rucksack)//2
    box1 = rucksack[:mid]
    box2 = rucksack[mid:]

    shared = [item for item in box1 if item in box2]
    ans+=priority(shared[0])

print(ans)