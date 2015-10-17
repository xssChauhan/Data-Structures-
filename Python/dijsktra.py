from heapq import heappush, heappop


def dikstra(graph,s):
	dist = dict()
	n = len(graph.keys())
	for v in graph:
		dist[v] = float('inf')
	dist[s] = 0
	Q = list()
	heappush(Q,(dist[s],s))
	while Q:    #Q => X !=V 
		d,u = heappop(Q)
		if d < dist[u]:
			dist[u] = d
		for v in graph[u]:
			if dist[v] > dist[u] + graph[u][v]:
				dist[v] = dist[u] + graph[u][v]
				heappush(Q,(dist[v],v))
	return dist

if __name__ == '__main__':
	a = input()
    
    dist = dict()
	for _ in range(a):
		g = dict()
        strs = []
		vertices,edges = (int(x) for x in raw_input().split())
		for i in xrange(1,vertices+1):
			g[int(i)] = dict()
		for e in xrange(edges):
			u,v = [int(x) for x in raw_input().split()]
			g[int(u)][int(v)] = 6
        	s = input()
        	dist.append(dikstra(g, s))  
        	
        for i in dist[]:
            for k in i.values()[1:]:
                strs.append(k)
            strs.append('\n')
            print strs
            

