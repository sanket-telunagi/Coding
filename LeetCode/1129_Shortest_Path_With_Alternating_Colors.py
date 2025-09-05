import collections
from typing import *

def shortestAlternatingPaths(n: int, redEdges: List[List[int]], blueEdges: List[List[int]]) -> List[int]:
    red = collections.defaultdict(list)
    blue = collections.defaultdict(list)

    for a,b, u, v in zip(redEdges, blueEdges) :
        red[a].append(b)
        blue[u].append(v)
    
    ans = [-1] * n 
    dq = Deque()
    
    # [node, len, prev_edge_color]
    visit = set()
    visit.add((0,None))

    while dq :
        node, length, edge = dq.popleft()
        if (ans[node] == -1) :
            ans[node] = length
        
        if edge != "RED" :
            for i in red[node] :
                if (i, "RED") not in visit :
                    visit.add((i,"RED"))
                    dq.append((i, length + 1, "RED"))
        
        if edge != "BLUE" :
            for i in blue[node] :
                if (i, "BLUE") not in visit :
                    visit.add((i,"BLUE"))
                    dq.append((i, length + 1, "BLUE"))

    return ans
    