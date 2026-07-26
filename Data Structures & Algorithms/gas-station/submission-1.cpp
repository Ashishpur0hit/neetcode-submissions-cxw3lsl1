class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(),total_gas=0,total_cost=0,ans;
        for(int i=0;i<n;i++) total_gas+=gas[i],total_cost+=cost[i];
        if(total_cost>total_gas) return -1;
        vector<int>v(n);
        for(int i=0;i<n;i++)
        {
            if(i==0) v[i]=gas[i]-cost[i];
            else if(v[i-1]>=0) v[i]=v[i-1]+gas[i]-cost[i];
            else v[i]=gas[i]-cost[i];
        }
        for(int i=n-1;i>=0;i--) 
        {
            
            if(v[i]>=0) ans=i;
            else break;
            cout<<v[n-1-i]<<" ";
        }
        return ans;

    }
};
