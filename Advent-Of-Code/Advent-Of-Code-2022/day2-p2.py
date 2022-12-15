f=open("Advent-Of-Code\Advent-Of-Code-2022\day2-data.txt")
outcomes={
    'X':0,
    'Y':3,
    'Z':6,
    'A X': 3,
    'A Y': 1,
    'A Z': 2,
    'B X': 1,
    'B Y': 2,
    'B Z': 3,
    'C X': 2,
    'C Y': 3,
    'C Z': 1,
}
result=0
for match in f:
    match=match.rstrip()
    result+=outcomes[match]+outcomes[match[2]]
print(result)