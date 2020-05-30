class Solution {

/*    
public:
    int rob(vector<int>& nums) {
        
        
            if(nums.size()==0)
                return 0;
            if(nums.size()==1)
                return nums[0];
            if(nums.size()==2) 
                return max(nums[0],nums[1]);
            
        int dp[nums.size()];
        int i,j,n=nums.size();
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(i=2; i<n;i++){
            dp[i] = max(dp[i-2]+nums[i],dp[i-1]);
        }
        
        return dp[n-1];
        
        space O(n)
        TimeO(n)
    }*/
    
    public:
    int rob(vector<int>& nums) {
        
        
            if(nums.size()==0)
                return 0;
            if(nums.size()==1)
                return nums[0];
            if(nums.size()==2) 
                return max(nums[0],nums[1]);
      
        
        int i,n=nums.size();
        int first,second,temp;
        first = nums[0];
        second = max(nums[0],nums[1]);
        for(i=2; i<n;i++){
            temp = second;
            second = max(first+nums[i],second);
            first = temp;
        }
        
        return second;
        
        //space O(1)
        //TimeO(n)
    }
};


 













