class Solution {
public:
    int subarraysWith_AtMost_K_Distinct(vector<int>& A, int K) {
        
        map<int, int> m;
        for(int i = 0; i < A.size(); i++) m[A[i]] = 0;
        
        vector<int> count(A.size() + 1);
        int ans = 0;
        int left = 0;
               
        for(int right = 0; right < A.size(); right++){
            /*
            if(m.find(A[right]) == m.end()){
                m[ A[right] ] = 1;
                K -= 1;
            }
            else m[ A[right] ] += 1;
            */
            if( m[A[right]]++ == 0) K--;
            //if( count[A[right]]++ == 0) K--;
            while(K < 0){
                if( --m[A[left++]] == 0 ) ++K;
                //if (--count[A[left++]] == 0) ++K;
            }
            
            ans += (right - left + 1);
        }
        
        return ans;
    }
    
    
    int subarraysWithKDistinct(vector<int>& A, int K){
        return ( subarraysWith_AtMost_K_Distinct(A, K) - subarraysWith_AtMost_K_Distinct(A, K - 1) );
    }
};