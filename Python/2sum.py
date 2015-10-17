import bisect
boundary = 10000
def TwoSum(array):
	t = set()
	for i in array:
		low = bisect.bisect_left(array, -boundary-i)
		high = bisect.bisect_right(array, boundary - i)
		t |= set([i+j for j in array[low:high]])
	return t

def main():
	file = open('2sum.txt')
	a = list()
	for line in file:
		a.append(int(line.split()[0]))
	a.sort()
	return  len(TwoSum(a))




if __name__ == '__main__':
	print main()