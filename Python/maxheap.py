import minheap from minheap

class maxheap(minheap):

    def __str__(self):
        return "Maxheap of %s elements" %len(self.heap)

    def heapify(self,i):
        l = self.lefchild(i)
        r = self.rightchild(i)

        max  = i

        if l < self.heaplength() and self.leftchild[i] > self.heap[i]:
            max = l

        if r < self.heaplength() and self.rightchild[i] > self.heap[max]:
            max = r

        if max != i:
            self.heap[i] , self.heap[max] = self.heap[max] , self.heap[i]
            self.heapify(max)

    def insert(self, data):
         i = self.heaplength()
         self.heap.append(data)
         parent = self.parent(i)
         while parent != [] and self.heap[i] > self.heap[parent] :
             self.heap[i] , self.heap[parent] = self.heap[parent] , self.heap[i]
             i = parent
             parent = self.parent[i]
