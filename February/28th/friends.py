
def friends (names, queries):
    N = 26
    graph = [[float('inf') for _ in range(N)] for _ in range(N)]
    # create graph
    for name in names:
        for i in range(len(name)):
            graph[ord(name[i])-ord('A')][ord(name[i])-ord('A')] = 0
            for j in range(i+1,len(name)):
                graph[ord(name[i])-ord('A')][ord(name[j])-ord('A')] = 1
                graph[ord(name[j])-ord('A')][ord(name[i])-ord('A')] = 1

    # print(graph)
    
    # floyd-warshall
    for k in range(N):
        for i in range(N):
            for j in range(N):
                graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j])

    def answer_queries(x,y):
        min_distance = float('inf')
        for c in x:
            for d in y:
                min_distance = min(min_distance, graph[ord(c)-ord('A')][ord(d)-ord('A')])

        if min_distance == float('inf'):
            return -1
        else:
            return min_distance+2

    result = []
    for i in range(len(queries)):
        x = names[queries[i][0]-1]
        y = names[queries[i][1]-1]
        result.append(answer_queries(x,y))

    return result

N = int(input())

for i in range(N):
    input1 = [int(x) for x in input().split()]
    names = input().split()
    queries = []
    for j in range(input1[1]):
        queries.append([int(x) for x in input().split()])
    result = friends(names,queries)
    print("Case #{}: ".format(i+1), end="")
    print(*result)


