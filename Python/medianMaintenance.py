from heapq import heappush , heappop


def maintain_median(stream):
    
    out = [stream.pop(0)]
    heap_lo, heap_hi = [], [out[0]]
    while stream:
        num = stream.pop(0)
        if num > heap_hi[0]:
            if len(heap_hi) > len(heap_lo):
                heappush(heap_lo, heappop(heap_hi))
                heappush(heap_hi, num)
            elif len(heap_hi) <= len(heap_lo):
                heappush(heap_hi,num)
        elif num <= heap_hi[0]:
            if len(heap_hi) > len(heap_lo):
                heappush(heap_lo,num)
            elif len(heap_hi) < len(heap_lo):
                heappush(heap_hi, num)
            elif len(heap_hi) == len(heap_lo):
                heappush(heap_lo, num)
        if len(heap_hi) > len(heap_lo):
            out.append(heap_hi[0])
        elif len(heap_lo) > len(heap_lo):
            out.append(heap_lo[len(heap_lo)] - 1)
        print heap_hi
        print heap_lo
    return out


def main():
    stream = []
    with open('Median.txt') as file_in:
    #with open('test.txt') as file_in:
        for line in file_in:
            num = int(line.strip())
            stream.append(num)
    medians = maintain_median(stream)
    return sum(medians) % 10000


if __name__ == '__main__':
    print main()
