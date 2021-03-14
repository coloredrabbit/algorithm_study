import sys
from collections import deque

T = int(sys.stdin.readline())
for t in range(1, T+1):
    R, C = map(int, sys.stdin.readline().split())
    S = [list(sys.stdin.readline().rstrip()) for r in range(R)]

    def getOverallDeliveryTime():
        global R, C, S
        q = deque()
        dRow = [1, -1, 0, 0]
        dCol = [0, 0, 1, -1]
        check = [[False for c in range(C)] for r in range(R)]
        for r in range(R):
            for c in range(C):
                if S[r][c] == '1':
                    q.append((r, c, 0))
                    check[r][c] = True
        
        maxStep = 0
        while q:
            r, c, step = q.popleft()
            maxStep = max(maxStep, step)
            for d in range(4):
                newR = r + dRow[d]
                newC = c + dCol[d]
                if newR < 0 or newR >= R or newC < 0 or newC >= C:
                    continue
                if check[newR][newC]:
                    continue
                q.append((newR, newC, step+1))
                check[newR][newC] = True
        return maxStep

    answer = getOverallDeliveryTime()
    for r in range(R):
        for c in range(C):
            if S[r][c] == '0':
                S[r][c] = '1'
                answer = min(getOverallDeliveryTime(), answer)
                S[r][c] = '0'
    print("Case #" + str(t) + ": " + str(answer))
