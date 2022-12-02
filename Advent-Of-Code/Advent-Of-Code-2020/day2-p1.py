f = open("Advent Of Code/2020/day2-data.txt")
correct = 0
for line in f:
    s = line.split()
    letter = s[1][0]
    num = s[2].count(letter)
    s = s[0].split("-")
    if num>=int(s[0]) and num<=int(s[1]): correct+=1
print(correct)