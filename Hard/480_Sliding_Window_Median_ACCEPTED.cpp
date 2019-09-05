class Solution {
public:
    multiset<double> lower; //max_heap
    multiset<double, greater<double> > higher; //min_heap
    
    void print(){
        cout << "lower (max_heap): " << endl;
        multiset <double, greater <double> > :: iterator itr_lower;
        for(itr_lower = lower.begin(); itr_lower != lower.end(); ++itr_lower)
            cout << *itr_lower << " ";
        cout << endl;
        cout << "higher (min_heap): " << endl;
        multiset <double, greater <double> > :: iterator itr_higher;
        for(itr_higher = higher.begin(); itr_higher != higher.end(); ++itr_higher)
            cout << *itr_higher << " ";
        cout<< "END" << endl;
    }
    
    void add(double num){
        lower.insert(num);
        if(lower.size() <= 1) return;
        multiset <double, greater <double> > :: iterator itr_lower = lower.begin();
        
        higher.insert(*itr_lower);
        //cout << "Before erase: " << lower.size() << endl;
        lower.erase(lower.find(*itr_lower));
        //cout << "After erase: " << lower.size() << endl;
        
        if(lower.size() < higher.size()){
            multiset <double> :: iterator itr_higher = higher.begin();
            lower.insert(*itr_higher);
            higher.erase(higher.find(*itr_higher));
        }
    }  
    
    double avg(){
        multiset <double, greater <double> > :: iterator itr_lower = lower.begin();
        multiset <double> :: iterator itr_higher = higher.begin();
        //cout<< "lower, higher: " << *itr_lower << " " << *itr_higher << endl;
        if(lower.size() == higher.size()) return (*itr_lower + *itr_higher) / 2;
        return *itr_lower;
    } 
    
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        if(nums.size() == 0) return ans;
        int j = 0;
        for(int i = 0; i < nums.size(); i++){
            add((double) nums[i]);
            //print();
            if(i - j >= k - 1){
                ans.push_back(avg());
                if(lower.find(nums[j])==lower.end())
                    higher.erase(higher.find(nums[j]));
                else
                    lower.erase(lower.find(nums[j]));
                j++;
            }   
        }
        return ans;
    }
};