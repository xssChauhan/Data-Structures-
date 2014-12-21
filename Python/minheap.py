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
    def heapify(self):



