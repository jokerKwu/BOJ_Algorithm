from collections import deque
import sys
input = sys.stdin.readline
A, B, N, M = map(int,input().split())
m_x = [1, -1, A, B, -A, -B, A, B]
visit = [0 for _ in range(100001)]
cnt = [0 for _ in range(100001)]
q = deque()
visit[N] = 1
q.append(N)
def bfs():
    while q:
        x = q.popleft()
        for i in range(8):
            if i < 6:
                nx = x + m_x[i]
                if 0<=nx<=100000 and visit[nx] == 0:
                    visit[nx] = 1
                    q.append(nx)
                    cnt[nx] = cnt[x] + 1
            else:
                nx = x * m_x[i]
                if 0<=nx<=100000 and visit[nx] == 0:
                    visit[nx] = 1
                    q.append(nx)
                    cnt[nx] = cnt[x] + 1
bfs()
print(cnt[M])