import heapq

def ls3(A, B, C):
    if A == 0 and B == 0 and C == 0:
        return ""
    pq = []
    res = ""
    for k, v in ('a', A), ('b', B), ('c', C):
        heapq.heappush(pq, (-v, k))
        #print(-v, k)
    preV, preK = 0, ''
    while pq:
        v, k = heapq.heappop(pq)
        if preV:
            heapq.heappush(pq, (preV, preK))
            preV, preK = 0, ''
        if res[-2:] == k * 2:
            preV, preK = v, k
        else:
            res += k
            if v != -1:
                heapq.heappush(pq, (v + 1, k))
    return res


def f(A, B, C):
    if A == 0 and B == 0 and C == 0:
        return ""
    sum_original = A + B + C
    v_1 , v_2, v_3 = 0, 0, 0
    c_1, c_2, c_3 = '.', '.', '.'
    
    if A >= B and A >= C:
        v_1 = A
        c_1 = 'a'
        if B >= C:
            v_2 = B
            c_2 = 'b'
            v_3 = C
            c_3 = 'c'
        else:
            v_2 = C
            c_2 = 'c'
            v_3 = B
            c_3 = 'b'

    elif B >= A and B >= C:
        v_1 = B
        c_1 = 'b'
        if A >= C:
            v_2 = A
            c_2 = 'a'
            v_3 = C
            c_3 = 'c'
        else:
            v_2 = C
            c_2 = 'c'
            v_3 = A
            c_3 = 'a'

    elif C >= A and C >= B:
        v_1 = C
        c_1 = 'c'
        if A >= B:
            v_2 = A
            c_2 = 'a'
            v_3 = B
            c_3 = 'b'
        else:
            v_2 = B
            c_2 = 'b'
            v_3 = A
            c_3 = 'a'            
    
    i = 0
    str = ""
    while v_1 > 0:
        if v_1 >= 1:
            str += c_1
            v_1 -= 1
        if v_1 >= 1:
            str += c_1
            v_1 -= 1
        
        if v_2 == 0 and v_3 == 0:
            break
        if v_2 > 0:
            str += c_2
            str += '.'
            v_2 -= 1
        
        if v_2 == 0 and v_3 > 0:
            str += c_3
            str += '.'
            v_3 -= 1
        
        if v_1 == 0:
            break
    
    ans = ""
    if v_2 == 0 and v_3 == 0 and v_1 >= 0:    
        for i in range(0 , len(str)):
            if str[i] != '.':
                ans += str[i]
    
    elif v_1 == 0:
        if v_2 < v_3:
            temp = v_2;
            v_2 = v_3
            v_3 = temp
            
            c_temp = c_2;
            c_2 = c_3
            c_3 = c_temp
        
        #print('v_2:', v_2, 'v_3:', v_3)
        #print('c_2:', c_2, 'c_3:', c_3)
        while v_2 > 0:
            if v_2 >= 1:
                str += c_2
                str += '.'
                v_2 -= 1
            if v_2 >= 1:
                str += c_2
                str += '.'
                v_2 -= 1
                
            if v_2 == 0:
                break
            
            if v_3 == 0: 
                break
            
            if v_3 > 0:
                str += c_3
                str += '.'
                v_3 -= 1
        
        if v_2 > 0: #assuming v_3 = 0
            if v_2 >= 2:
                str = c_2 + c_2 + str
                v_2 -= 2
            
            for i in range(1, len(str) - 1):
                if str[i] == '.' and ( (str[i-1] == c_2 and str[i+1] != c_2) or (str[i+1] == c_2 and str[i-1] != c_2) ):
                    lst = list(str)
                    lst[i] = c_2
                    str = ''.join(lst)
                    v_2 -= 1
                if v_2 <= 0:
                    break;
                    
        elif v_3 > 0:
            if v_3 >= 2:
                str = c_3 + c_3 + str
                v_3 -= 2
            
            for i in range(1, len(str) - 1):
                if str[i] == '.' and ( (str[i-1] == c_3 and str[i+1] != c_3) or (str[i+1] == c_3 and str[i-1] != c_3) ):
                    lst = list(str)
                    lst[i] = c_3
                    str = ''.join(lst)
                    v_3 -= 1
                if v_3 <= 0:
                    break
            
    if ans == "":  
        for i in range(0 , len(str)):
            if str[i] != '.':
                ans += str[i]
    
    sum_str = len(ans)
    #print(sum_original, sum_str, sum_original==sum_str)
    #print(v_1, v_2, v_3)
    if sum_original != sum_str:
        print (A, B, C)
        print(str)
        print (ans)
    return ans


    
A, B, C = 1, 1, 2
#their = ls3(A, B, C)
#mine = f(A, B, C)
#print(mine)
#print(their, mine, their==mine)


MAX = 6
MIN = 1
for A in range(MIN, MAX):
    for B in range(MIN, MAX):
        for C in range(MIN, MAX):
            their = ls3(A, B, C)
            mine = f(A, B, C)
            their_len = len(their)
            my_len = len(mine)
            tot_len = A + B + C
            #if my_len != tot_len and their_len == tot_len:# and their_len - my_len > 1:
                #print(my_len, their_len)
                #print(A, B, C)
                #print("mine: ", mine)
                #rint("their: ", their)
                #print("------------------")
                
            
            
            #print(A, B, C, A+B+C, "their_len: ", len(their), len(their)==(A+B+C), "mine_len: ", len(mine), len(mine)==(A+B+C))
            #print(their, mine, their==mine)
            #print("========================")    


#A, B, C = 0, 0, 0
#print(ls3(A, B, C))