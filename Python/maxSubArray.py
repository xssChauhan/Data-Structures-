def maxCrossSubArray(B,C):
	leftSum = None
	i = len(B)
	sum = 0
	for e in B[::-1]:
		sum = sum + e
		if sum > leftSum:
			leftSum = sum
			maxLeft = i
	rightSum = None
	i = len(C)
	sum = 0
	for 0:1:
		sum = sum + e
		if sum > rightSum:
			rightSum = sum
			maxRight = j


def maxSubArray(A):
	l = len(A)
	if l ==1 :
		return A,A[0]
	else:
		mid = l//2
		B = A[:mid]
		C = A[mid:]
		B,b = maxSubArray(B)
		C,c = maxSubArray(C)
		D,d = maxCrossSubArray(B,C)
		z = zip((B,b),(C,c),(D,d))
		m = None
		index = 0
		for i,e in enumerate(z[1]):
			if e > m:
				m = e
				index = i
		return z[0][i],z[1][i]