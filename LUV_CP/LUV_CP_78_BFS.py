def BFS() :
    pass

n = int(input())
graph = dict()
for i in range(n) :
    v1, v2 = map(int, input().split())
    graph[v1].append(v2)
    graph[v2].append(v1)

print(graph)