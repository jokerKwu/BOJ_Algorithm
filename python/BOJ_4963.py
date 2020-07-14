import sys
from collections import deque
input = sys.stdin.readline
queue = deque()

m_xy = [(1, 1), (-1, -1), (1, -1), (-1, 1),(-1,0),(1,0),(0,1),(0,-1)]

while True:
    w, h = map(int, input().split())
    board = []
    answer = 0
    if w == 0 and h == 0:
        break
    check = [[0]*w for _ in range(h)]

    for i in range(h):
        board.append(list(map(int, input().split())))

    for i in range(h):
        for j in range(w):
            if board[i][j] == 1 and check[i][j] == 0:
                answer += 1
                queue.append((j, i))

                while queue:
                    cx, cy = queue.popleft()
                    for k in range(8):
                        nx, ny = cx + m_xy[k][0], cy + m_xy[k][1]
                        if 0 <= nx < w and 0 <= ny < h:
                            if check[ny][nx] == 0 and board[ny][nx] == 1:
                                check[ny][nx] = 1
                                queue.append((nx, ny))
    print(answer)
