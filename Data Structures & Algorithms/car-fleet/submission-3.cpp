class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int,int>>temp(n);
        stack<double>s;
        for(int i=0;i<n;i++) temp[i]={position[i],speed[i]};
        sort(temp.rbegin(),temp.rend());

        for(int i=0;i<n;i++)
        {
            double time =(double) (target - temp[i].first)/temp[i].second;
            cout<<time<<endl;
            if(s.empty()) s.push(time);
            else 
            {
                if(time>s.top()) s.push(time);
                
            }
        } 
        return s.size();

    }
};
