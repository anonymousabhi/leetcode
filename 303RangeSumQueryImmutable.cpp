class NumArray {
public:
    int prefix[1000000];
    NumArray(vector<int>& nums) {
        
        if(nums.size()==0)
            return ;
        prefix[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        
        
        
    }
    
    int sumRange(int i, int j) {
        
        if(i==0)
            return prefix[j];
        return prefix[j] - prefix[i-1];
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 
 
 
     0  1  2.  3. 4. 5    
    -2  0  3  -5  2 -1
    -2. -2 1  -4 -2.-3
 
 
 
 
 */
