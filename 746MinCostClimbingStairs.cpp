class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int dp[cost.size()+1];
        
        dp[0] = 0;
        dp[1] = min(cost[1],dp[0]);
        
        for(int i=2;i<=cost.size();i++){
            dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        }
        //if(dp[cost.size()-1]+cost[cost.size()-1])
        
        return dp[cost.size()];
    }
};


/*

1 100 1 1 1 100 1 1 100 1
1 1   2 2 3 3.  4 5.    6

0001
000


*/
