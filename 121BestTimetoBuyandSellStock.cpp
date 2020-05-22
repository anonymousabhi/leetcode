class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)
            return 0;
        
        int arr[prices.size()];
        
        int mini=prices[0] , maxi=-1000000;
        arr[0]=0;
        for(int i=1;i<prices.size();i++){
            arr[i] =  prices[i] -mini;
            mini = min(mini,prices[i]);
            maxi = max(maxi,arr[i]);
            cout<<arr[i]<<" "<<mini<<" "<<maxi<<endl;
        }
        if(maxi<0)
            return 0;
        return maxi;
    }
};

/*

7 1 5 3 6 4
0 1 4 2 5 3

7  1 1 1 1 1
0 -6 4 2 5 3

7 6  4  3  1
0 -1 -2 -1 
*/
