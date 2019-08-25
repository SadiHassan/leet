class FileSystem {
public:
    map<string, int> m;
    
    
    FileSystem() {
        
    }
    
    bool create(string path, int value) {
        int ind;
        for(int i = path.size() - 1; i >= 0; i--)
            if(path[i] == '/'){
                ind = i;
                break;
            }
        if(ind == 0){ //new root path
            m[path] = value;
            return true;
        }
        
        string root = path.substr(0, ind);
        if(m.find(root) == m.end()) return false;
        
        
        m[path] = value;
        
        return true;        
    }
    
    int get(string path) {
        if(m.find(path) == m.end()) return -1;
        return m[path];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->create(path,value);
 * int param_2 = obj->get(path);
 */