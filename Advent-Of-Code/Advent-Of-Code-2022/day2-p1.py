f=open("Advent-Of-Code\Advent-Of-Code-2022\day2-data.txt")
score={
    'X':1,
    'Y':2,
    'Z':3,
    'lost':0,
    'draw':3,
    'win':6
}
result=0
for match in f:
    match=match.rstrip()
    if match[0]=='A':
        if match[2]=='Y': result+=score['win']
        elif match[2]=='Z': result+=score['lost']
        else: result+=score['draw']
        result+=score[match[2]]
    elif match[0]=='B':
        if match[2]=='X': result+=score['lost']
        elif match[2]=='Z': result+=score['win']
        else: result+=score['draw']
        result+=score[match[2]]
    elif match[0]=='C':
        if match[2]=='Y': result+=score['lost']
        elif match[2]=='X': result+=score['win']
        else: result+=score['draw']
        result+=score[match[2]]
print(result)