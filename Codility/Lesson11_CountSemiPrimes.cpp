// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(int N, vector<int> &P, vector<int> &Q) {
     // write your code in C++14 (g++ 6.2.0)
    vector<int> prime(N + 1, true);
    vector<int> coprime(N + 1, false);
    prime[1] = false;
    
    for(int i = 2; i * i <= N; i++){
        if(!prime[i]) continue;
        for(int j = i * i; j <= N; j += i){
            prime[j] = false;
        }
    }
    
    for(int i = 2; i * i <= N; i++){
        if(!prime[i]) continue;
        int tot = 0;
        for(int j = i; j <= N; j += i){
            tot++;
            if(prime[tot]) coprime[j] = true;
        }    
    }
    //for(int i = 0; i <= N; i++) cout << i << " => " << prime[i] << endl;
    //cout << "coprime: " << endl;
    //for(int i = 0; i <= N; i++) cout << i << " => " << coprime[i] << endl;
    
    vector<int> dp(N + 2, 0);
    dp[0] = 0;
    dp[1] = 0;
    
    for(int i = 2; i <= N; i++){
        dp[i] = dp[i - 1];
        if(coprime[i]) dp[i] += 1; 
    }
    //for(int i = 0; i <= N; i++) cout << i << " => " << dp[i] << endl;
    vector<int> ans;
    
    for(int i = 0; i < P.size(); i++){
        //cout << "dp: " << Q[i] << " -- " << P[i] << " -- " << dp[ Q[i] ] << " -- " << dp[ P[i - 1] ] << endl;
        ans.push_back(dp[ Q[i] ] - dp[ P[i] - 1 ]);    
    }
    
    return ans;
}