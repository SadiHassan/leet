//Approach 1: Simple Sorting --- TLE
// TLE TLETLE TLE TLE TLE TLE TLE TLE TLE TLE TLE TLE TLE TLE TLE TLE TLE 
class MedianFinder {
public:
    /** initialize your data structure here. */
    vector<double> store;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        store.push_back(num);
    }
    
    double findMedian() {
        sort(store.begin(), store.end());
        
        int n = store.size();
        return( n & 1 ? store[n / 2] : (store[n / 2] + store[n / 2 - 1]) / 2);
    }
};

//Approach 2: Inserion Sort -- ACCEPTED but SLOWWWWWWWW

class MedianFinder {
public:
    vector<double> store;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(store.empty())
            store.push_back(num);
        else
            store.insert(lower_bound(store.begin(), store.end(), num),
                        num);
    }
    
    double findMedian() {
        
        int n = store.size();
        return( n & 1 ? store[n / 2] : (store[n / 2] + store[n / 2 - 1]) / 2);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

//Approach - 3: Two Heaps (Priority Queue)
class MedianFinder {
public:
    vector<double> store;
    priority_queue<int> lower; //MAX heap
    priority_queue<int, vector<int>, greater<int>> higher; //MIN heap
    
    MedianFinder() {
        
    }
    
    //My Version: I understood WHY it was wrong. I will reexplain it to myself later
    /*
    void addNum(int num) {
        higher.push(num);
        if(lower.size() < higher.size()){
            lower.push(higher.top());
            higher.pop();
        }
            
    }
    */
    
    //Tutorial Version
    void addNum(int num) {
        lower.push(num);
        higher.push(lower.top());
        lower.pop();
        if(lower.size() < higher.size()){
            lower.push(higher.top());
            higher.pop();
        }
            
    }
    double findMedian() {      
        if(lower.size() > higher.size()){
           return (double) lower.top();
        }
        return (double) (lower.top() + higher.top()) / 2;
    }
};