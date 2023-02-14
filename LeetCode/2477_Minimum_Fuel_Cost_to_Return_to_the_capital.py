import math
from typing import *
def minimumFuelCost(roads: List[List[int]], seats: int) -> int:
    g = dict(list)
    for v1, v2 in roads :
        g[v1].append(v2)
        g[v2].append(v1)
    
    def DFS(node, par) :
        nonlocal fuel 
        passengers = 0
        for child in g[node] :
            if child != par  :
                p = DFS(child, node)
                passengers += p
                fuel += int(math.ceil(p / seats))
        return passengers + 1
    
    fuel = 0
    DFS(0, -1)
    return fuel
