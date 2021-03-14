import sys

T = int(sys.stdin.readline())
for t in range(1, T+1):
    N, P = map(int, sys.stdin.readline().split())
    S = list(map(int, sys.stdin.readline().split()))
    S.sort()

    L, R = 0, P-1
    subTotal = sum(S[L:R+1])
    answer = S[R]*P - subTotal
    while True:
        answer = min(answer, S[R]*P - subTotal)
        subTotal -= S[L]
        L += 1
        R += 1
        if R == N:
            break
        subTotal += S[R]
    print("Case #" + str(t) + ": " + str(answer))
    