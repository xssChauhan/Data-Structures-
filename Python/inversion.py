def inversion(m):
	'''Solves inversion problem in n-square time'''
	l = 0
	for index, element in enumerate(m):
		temp = m[index:]
		for i,e in enumerate(temp):
			if e < element:
				l = l + 1

	return l

def SortCount(A):
	'''solves inversion problem in nlogn time'''
	l = len(A)
	if l> 1:
		n = l//2
		C = A[:n]
		D = A[n:]
		C,c = SortCount(C)
		D,d = SortCount(D)
		B,b = MergeCount(C,D)
		return B, b+c+d
	else:
		return A,0

def MergeCount(A,B):
	count = 0
	M = []
	while A and B:
		if A[0] <= B[0]:
			M.append(A.pop(0))
		else:
			count += len(A)
			M.append(B.pop(0))
	M += A + B
	return M, count

if __name__== '__main__':
	a = open('IntegerArray.txt','r')
	a = a.read()
	a = a.split('\r\n')
	a.pop()
	l = []
	for i in a:
		l.append(int(i))
	print SortCount(l)[1]
