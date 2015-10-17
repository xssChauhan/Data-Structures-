import sys
sys.setrecursionlimit(15000)
comparisons = 0

class countr:
	count = 0
	def __call__(self,n):
		countr.count += n
		print(countr.count)


def quicksort1(list):
	if list == []:
		return []
	else:
		pivot = list[0]
		lesser = quicksort1([x for x in list[1:] if x < pivot])
		greater = quicksort1([x for x in list[1:] if x >=  pivot])
		return lesser + [pivot] + greater



def medianPivot(a):
	'''finds the median of the first, middle and the last element of the array a'''
	l = []
	ln = len(a) - 1
	for t in [0,ln//2, ln]:
		l.append(a[t])
	l.sort()
	
	return l[len(l)//2]


def partition(a,l,r):
	#a[0],a[r-1] = a[r-1],a[0]
	p = medianPivot(a)
	pindex = a.index(p)
	a[pindex],a[l] = a[l],a[pindex]
	global comparisons
	
	i =  1
	comparisons += r
	for j in range(1,r+1):
		if a[j] < p:
			a[j],a[i] = a[i],a[j]
			i += 1
	a[0],a[i-1] = a[i-1],a[0]
	
	
	return a,i

def quicksort(list):
	l = len(list)
	if l == 0 or l == 1:
		return list
	if l:
		a,i = partition(list,0,l-1)
		#print 'left'
		left = quicksort(a[:i-1]) #the pivot is already in its place
		#print 'right'
		right = quicksort(a[i:])
	return left+right
	



if __name__ == '__main__':
	

	a = open('QuickSort.txt','r')
	a = a.read()
	a = a.split('\r\n')
	a.pop()
	l = []

	for i in a:
		l.append(int(i))
	quicksort(l)
	print comparisons

