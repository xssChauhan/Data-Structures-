import math
class minheap:
    def __init__(self, nums = 0):
        self.heap = []
        if nums:
            self.buildheap(nums)

    def __str__(self):
        return "Minheap with %d items" % len(self.heap)

    #returns the length of the heap
    def heaplength(self):
        return len(self.heap)

    #Returns the status of a node as a leaf
    def isleaf(self,i):
        if self.leftchild(i) and self.rightchild(i) == False:
            return True

    #Returns the Parent Element of the node
    def parent(self, i):
        if i == 0:
            return -1
        return math.floor((i-1)/2)

    #Returns the left child of the node
    def leftchild(self,i):
        left  = 2*i + 1
        if left > len(self.heap):
            return -1
        return left

    #Returns the right child of the node
    def rightchild(self, i):
        right  = 2*i + 2
        if right > self.heaplength():
            return -1
        return right

    #Heapify the heap
    def heapify(self, i):

        l = self.leftchild(i)
        r = self.rightchild(i)
        min = i
        if( l <  self.heaplength() and  self.heap[min] > self.heap[l] ):
            min = l;
        if( r < self.heaplength() and self.heap[min] > self.heap[r] ):
            min = r;

        if( min != i):
            """Swap the element with i"""
            self.heap[i] , self.heap[min] = self.heap[min] , self.heap[i]

        self.heapify(min)

    #Inserting element into the heap
    def insert(self, data):
        self.heap.append(data)
        i = self.heaplength() - 1
        parent = self.parent[i]
        while parent ! = [] and self.heap[i] < self.heap[parent]:
            self.heap[i], self.heap[parent] = self.heap[parent], self.heap[i]
            i = parent
            parent = self.parent(i)

    #Building the heap
    def buildheap(self , nums):
        for i in xrange(nums):
            self.heap[i] = input()

    #Deleting the topmost element of the heap, which in this case is the minimum element of the heap
    def deletemin(self):
        """Implements the function of popping from the heap"""
        if self.heaplength() == 0 :
            return -1
        data = self.heap[0]
        self.heap = self.heap[1:]
        self.heapify(0)
        return data










