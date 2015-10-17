from heapq import merge

def merge_sort(m):
	if len(m) <= 1:
		return m
	middle = len(m)//2

	left = m[:middle]
	right = m[middle:]

	left = merge_sort(left)
	right = merge_sort(right)
	return list(merge(left,right))

if __name__ == '__main__':
	 print merge_sort([4,1,7,8,5,6,2,3])