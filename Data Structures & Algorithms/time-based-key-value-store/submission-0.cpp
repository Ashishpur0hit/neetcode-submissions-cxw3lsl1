class TimeMap {
public:
    unordered_map<string,unordered_map<int,string>> map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        if(map.find(key)==map.end()) return "";
        int seen=-1;
        for(auto x  : map[key])
        {
            if(x.first<=timestamp)
            {
                seen = max(seen,x.first);
            }
        }
        return (seen==-1)?"":map[key][seen];
    }
};
