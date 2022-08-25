from ast import List
from cmath import inf
import queue

class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        adjList = [[] for _ in range(n + 1)]
        for x in times:
            adjList[x[0]].append((x[1], x[2]))
        dist = [inf for _ in range(n + 1)]
        vis = [False for _ in range(n + 1)]

        dist[k] = 0
        vis[k] = True
        q = queue.Queue()
        q.put(k)
        while not q.empty():
            top = q.get()
            for x in adjList[top]:
                if dist[top] + x[1] < dist[x[0]]:
                    dist[x[0]] = dist[top] + x[1]
                    if not vis[x[0]]:
                        q.put(x[0])
            vis[top] = False
            res = max(dist[1:])
        return res if res != inf else -1