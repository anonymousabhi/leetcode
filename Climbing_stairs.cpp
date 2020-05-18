class Solution {
public:
    int fib(int n){
        if(n==1 || n==2 )
            return n;
        int arr[n+1];
        arr[1]=1;
        arr[2]=2;
        for(int i=3;i<=n;i++)
            arr[i] = arr[i-1] + arr[i-2];
        return arr[n];
    }
    
    int climbStairs(int n) {
        int ans = fib(n);
        return ans;
    }
};
