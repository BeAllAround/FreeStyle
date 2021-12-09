from functools import reduce

def parts_sums(ls):
        if len(ls) == 0:
	    return [0]
    totalSum=reduce(lambda a, b: a + b, ls)
    sumList=[totalSum]
    for i in range(1,len(ls)+1):
	totalSum-=ls[i-1]
        sumList.append(totalSum)
    return sumList
