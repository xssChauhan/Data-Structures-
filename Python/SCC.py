import sys
import copy
sys.setrecursionlimit(30000)
'''Defining Globals identified, finished, leaders'''
identified = {}
finished = {}
leaders = {}
N = 875714

def init():
	for i in range(0,N+1):
		identified[i] = 0
		finished[i] = 0
		leaders[i] = 0


def getGraphFromFile(filename):
	G = {}
	Grev = {}
	file = open(filename)
	for i in range(0,N+1):
		G[i] = []
		Grev[i] = []
	for line in file:
		a = int(line.split()[0])
		b = int(line.split()[1])
		
		Grev[b].append(a)
		G[a].append(b)
	return G, Grev

def DFSloop(graph):
	global t
	global s
	t = 0
	s = 0
	for i in range(N-1,-1,-1):
		s = i
		DFS(graph,i)

def DFS(graph, node):
	global t
	global s
	global identified
	global leaders
	global finished

	identified[node] = 1
	leaders[node] = s
	for e in graph[node]:
		if not identified[e]:
			DFS(graph,e)
	t += 1
	finished[node] = t

def main():
	g,grev = getGraphFromFile('SCC.txt')
	
	#the first DFS loop to mark the finishing time of each node
	DFSloop(grev)
	newGraph = {}
	for i in range(1,N+1):
		newGraph[i] = []

if __name__ == '__main__':
	main()




