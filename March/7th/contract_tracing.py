
def contact_tracing(meets,final_state):
    meets = [set(x) for x in meets]
    N = len(meets)
    init_state = final_state[:]
    def is_homogen(meet):
        
        s = set()
        for n in meet:
            s.add(final_state[n-1])
        
        if len(s) == 1:
            return True
        else:
            return False
        
    if N == 1:
        if is_homogen(meets[0]):
            return meets[0]
        else: 
            return None
    
    for i in range(N-1,0,-1):
        prev = meets[i-1].copy()
        curr = meets[i].copy()
        temp = prev - curr

        if not is_homogen(temp):
            # print(temp)
            return None
        else:
            person = prev.pop()
            # print(person)
            if final_state[person-1] == 0:
                init_state[person-1] = 0
                for p in prev:
                    # print(p)
                    init_state[p-1] = 0
        

    return init_state



    




in1 = input().split()
N = int(in1[1])
meets = []
for i in range(N):
    meet = [int(x) for x in input().split()]
    meets.append(meet[1:])
final_state = [int(x) for x in input().split()]

output = contact_tracing(meets,final_state)
if output:
    print('YES')
    print(' '.join([str(n) for n in output]))
else:
    print('NO')