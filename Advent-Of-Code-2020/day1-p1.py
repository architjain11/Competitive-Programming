f = open("Advent Of Code/2020/day1-data.txt")
l=list()
for num in f:
    l.append(int(num))
for i in l:
    diff = 2020-i
    if diff in l:
        print("Product of numbers is", i*diff)
        break