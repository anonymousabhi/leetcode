class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        int start = 0 , end =0 ,sum = 0;
        
        int ans = INT_MIN;
        
        while (end!=n){
            
            sum+=nums[end];
            ans = max (ans,sum);
            
            if(sum<0){
                start= end;
                sum=0;
            }
            end++;
        }
        return ans;
        
    }
};


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long max_so_far = nums[0];
        long max_till_here = nums[0];
        
        
        if(nums.size()==0)
            return  0;
        if(nums.size()==1)
            return nums[0];
        
        
        for(int i=1;i<nums.size();i++){
            max_till_here=max(max_till_here +nums[i] , long(nums[i]));
            max_so_far = max(max_till_here, max_so_far);
        }
        return max_so_far;
        
    }
};

/*
-2  1 -3 4 -1 2 1 -5 4 
 -  -  -                  
                                                   
-2 -1 -4 0 -1 2 3 -2 2

*/
