def retype(N,K,S):
    return K-1 + min(N+1,K-S+N-S+1)
    
N = int(input())

for i in range(N):
    input1 = [int(x) for x in input().split()]
    print("Case #{}: {}".format(i+1, retype(*input1)))
    