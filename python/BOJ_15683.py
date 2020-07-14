from sys import maxsize, stdin
input = stdin.readline

N, M = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]

m_xy = [(-1, 0), (1, 0), (0, -1), (0, 1)] # 상하좌우
#카메라 번호마다 90도 회전 감시 영역
camera_dir = [[],
     [[0], [1], [2], [3]],
     [[0, 1], [2, 3]],
     [[0, 3], [3, 1], [1, 2], [2, 0]],
     [[0, 1, 2], [1, 2, 3], [2, 3, 0], [3, 0, 1]],
     [[0, 1, 2, 3]]]

cctv = []

blind = 0                       # 사각지대
answer = maxsize                # 답

for i in range(N):
    for j in range(M):
        if 0 < board[i][j] < 6:
            cctv.append((i, j))
        elif board[i][j] == 0:
            blind += 1

def solve(k, total):

    if k == len(cctv):               #재귀 종료 조건
        global answer
        answer = min(answer, total)
        return

    cx, cy = cctv[k]                 # x, y에서 감시
    num = board[cx][cy]              # cctv 번호

    for dirList in camera_dir[num]:  #카메라 번호에 따른 카메라 회전 목록을 가져온다.
        cnt = 0                      # 감시 개수
        tmp = []                     # 초기화를 위한 변수
        for d in dirList:            #리스트에 저장되어 있는 번호를 가져온다.
            c = 0                    #감시영역 카운트
            nx, ny = cx + m_xy[d][0], cy + m_xy[d][1]   #다음 좌표
            while -1 < nx < N and -1 < ny < M and board[nx][ny] != 6:   # 범위안에 있고 cctv를 통과할 수 있으므로
                if board[nx][ny] == 0:  # 0 이라면 7로 바꿔주고
                    c += 1
                    board[nx][ny] = 7
                    tmp.append((nx, ny))
                nx, ny = nx + m_xy[d][0], ny + m_xy[d][1]
            cnt += c
        solve(k + 1, total - cnt)   #재귀를 통해서 모든 카메라

        for nx, ny in tmp:          #감시했던 부분 초기화해주는 부분 (백트래킹)
            board[nx][ny] = 0

solve(0, blind)
print(answer)