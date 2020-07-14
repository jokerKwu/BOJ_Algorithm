from sys import stdin, maxsize
from queue import PriorityQueue
from heapq import heappop, heappush

input = stdin.readline
#pq = PriorityQueue()
INF = maxsize

N = int(input())
M = int(input())

dist = [INF] * (N+1)
edge = [[] for _ in range(N + 1)]

for i in range(M):
    u, v, w = map(int, input().split())
    edge[u].append((w, v))          # 가중치 , 노드

S, E = map(int, input().split())

def dijkstra():
    dist[S] = 0
    que = []
    heappush(que, (0, S))
    while que:
        curDist, curNode = heappop(que)
        if dist[curNode] < curDist:
            continue
        for nextDist, nextNode in edge[curNode]:
            if nextDist + curDist < dist[nextNode]:
                dist[nextNode] = nextDist + curDist
                heappush(que, (nextDist+curDist, nextNode))
    return 0

    '''
    pq.put((0, S))
    while pq.qsize() != 0:
        curDist, curNode = pq.get()
        if dist[curNode] < curDist:
            continue
        dist[curNode] = curDist
        for nextDist, nextNode in edge[curNode]:
            if dist[nextNode] > nextDist + curDist:
                nextDist += curDist
                pq.put((nextDist, nextNode))
    '''
dijkstra()
print(dist[E])