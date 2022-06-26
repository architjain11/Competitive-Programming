f = open("Advent Of Code/2020/day1-data.txt")
l1, l2=list(), list()
for num in f:
    l1.append(int(num))
for i in range(len(l1)-1):
    sum = 2020-l1[i] #sum of the remaining two numbers in the triplet
    for num in l1[i+1:]:
        l2.append(int(num))
    for j in l2:
        diff = sum-j
        if diff in l2:
            print("The product of triplets is", l1[i]*j*diff)
            break