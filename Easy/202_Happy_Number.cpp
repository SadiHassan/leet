//First time, used fast-slow pointers successfully :)
class Solution {
public:
    int getNextNumber(int N){
        int sum = 0;
        while(N > 0){
            sum = sum + (N % 10) * (N % 10);
            N = N / 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        if(n == 1) return true;
        int slow = getNextNumber(n);
        int fast = getNextNumber(slow);
        slow = n;
        while(slow != fast){
            slow = getNextNumber(slow);
            fast = getNextNumber(getNextNumber(fast));
            if(slow == 1 || fast == 1) return true;
            if(slow == fast) break;
        }
        
        return false;
    }
};