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