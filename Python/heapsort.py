import minheap

def generate(nums):
    h = minheap(nums)
    return[ h.heappop() for i in xrange(minheap.heaplength()) ]
