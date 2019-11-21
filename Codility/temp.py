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
        print(pq)
        v, k = heapq.heappop(pq)
        print(v,k)
        if preV:
            print("preV", preV)
            heapq.heappush(pq, (preV, preK))
            preV, preK = 0, ''
        if res[-2:] == k * 2:
            print("res : ", res)
            print("res[-2:] : ",res[-2:])
            print("k: ", k)
            print("k * 2", k * 2)
            preV, preK = v, k
        else:
            res += k
            if v != -1:
                heapq.heappush(pq, (v + 1, k))
    return res

def generate_string_core(A, B, C, AA, BB, CC):
    ans = "";
    while A > 0:
        if A > 0:
            ans += AA
            A -= 1
        if A > 0:
            ans += AA;
            A -= 1
        if B == 0 and C == 0:
            return ans
        if A == 0:
            break
        if B > 0:
            ans += BB
            B -= 1
        if C > 0:
            ans += CC
            C -= 1
    

    if B == 0:
        if C > 0: 
            ans = CC + ans
        C -= 1
        if C > 0: 
            ans = CC + ans
        C -= 1
        
        #NEW
        if len(ans) >= 2:
            ind = len(ans) - 1
            if ans[ind] != CC and ans[ind - 1] != CC and C > 0:
                ans += CC
                C -= 1
            ind = len(ans) - 1
            if ans[ind] != CC and ans[ind - 1] != CC and C > 0:
                ans += CC
                C -= 1    
        return ans;
    

    if C == 0:
        if B > 0: 
            ans = BB + ans
        B -= 1
        if B > 0: 
            ans = BB + ans
        B -= 1
        
        #NEW
        if len(ans) >= 2:
            ind = len(ans) - 1
            if ans[ind] != BB and ans[ind - 1] != BB and B > 0:
                ans += BB
                B -= 1
            ind = len(ans) - 1
            if ans[ind] != BB and ans[ind - 1] != BB and B > 0:
                ans += BB
                B -= 1
        
        return ans;

    while B > 0 and C > 0:
        if B > C:
            if B > 0:
                ans += BB
                B -= 1
            if B > 0:
                ans += BB
                B -= 1
            if C > 0:
                ans += CC
                C -= 1
        
        elif C > B:
            if C > 0:
                ans += CC
                C -= 1
            if C > 0:
                ans += CC 
                C -= 1
            if B > 0:
                ans += BB
                B -= 1
        
        else:
            if B > 0:
                ans += BB
                B -= 1
            if C > 0:
                ans += CC
                C -= 1
        
    

    if B == 0:
        if C > 0:
            ans = CC + ans
            C -= 1
        if C > 0:
            ans = CC + ans
            C -= 1
        return ans;
    
    if C == 0:
        if B > 0:
            ans = BB + ans
            B -= 1
        if B > 0:
            ans = BB + ans
            B -= 1
        return ans;
    
    return ans;


def generate_string(A, B, C):
    if A <= 0 and B <= 0 and C <= 0:
        return ""

    if A >= B and A >= C and B >= C:
        return generate_string_core2(A, B, C, 'a', 'b', 'c')
    
    elif A >= B and A >= C and C >= B: 
        return generate_string_core2(A, C, B, 'a', 'c', 'b')

    elif B >= A and B >= C and A >= C:
        return generate_string_core2(B, A, C, 'b', 'a', 'c')
    
    elif B >= A and B >= C and C >= A:
        return generate_string_core2(B, C, A, 'b', 'c', 'a')

    elif C >= A and C >= B and A >= B:
        return generate_string_core2(C, A, B, 'c', 'a', 'b');
    
    elif C >= A and C >= B and B >= A:
        return generate_string_core2(C, B, A, 'c', 'b', 'a');


def generate_string_core2(A, B, C, AA, BB, CC):
    ans = ""
    while C > 0:
        ans += AA
        ans += BB
        ans += CC
        A -= 1
        B -= 1
        C -= 1
    while A > 0 and B > 0:
        if A > B:
            if A > 0:
                ans += AA
                A -= 1
            if A > 0:
                ans += AA
                A -= 1
            if B > 0:
                ans += BB
                B -= 1
        
        elif B > A:
            if B > 0:
                ans += BB
                B -= 1
            if B > 0:
                ans += BB 
                B -= 1
            if A > 0:
                ans += AA
                A -= 1
        
        else:
            if A > 0:
                ans += AA
                A -= 1
            if B > 0:
                ans += BB
                B -= 1
    
    if A == 0:
        #Append B to the last
        ind = len(ans) - 1
        if ans[ind] == AA:
            if B > 0:
                ans += BB
                B -= 1
            if B > 0:
                ans += BB
                B -= 1
        else:
            if B > 0:
                ans += BB
                B -= 1
        #Append B to the first    
        if B > 0:
            ans = BB + ans
            B -= 1
        if B > 0:
            ans = BB + ans
            B -= 1
            

    if B == 0:
        #Append A to the last
        ind = len(ans) - 1
        if ans[ind] == BB:
            if A > 0:
                ans += AA
                A -= 1
            if A > 0:
                ans += AA
                A -= 1
        else:
            if A > 0:
                ans += AA
                A -= 1
        #Append B to the first    
        if A > 0:
            ans = AA + ans
            A -= 1
        if A > 0:
            ans = AA + ans
            A -= 1    
    
    return ans    

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


    
A, B, C = 10, 3, 2
their = ls3(A, B, C)
#mine = f(A, B, C)
#print(mine)
print(their)

MIN = 1
MAX = 100
'''
f = open('C:\\Users\sadi\GitHub\leet\Codility\expected.csv', 'w')
for A in range(MIN, MAX + 1):
    for B in range(MIN, MAX + 1):
        for C in range(MIN, MAX + 1):
            their = ls3(A, B, C)
            their_len = len(their)
            f.write(str(A) + "," + str(B) + "," + str(C) + "," + str(their_len) + "," + their + "\n")
f.close()
'''