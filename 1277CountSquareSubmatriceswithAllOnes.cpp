class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        if(n==0)
            return 0;
        
        int dp[n][m];
        
        for(int i= 0;i<n;i++){
            for(int j =0;j<m;j++){
                dp[i][j] = matrix[i][j];
            }
        }
        
        for(int i= 1;i<n;i++){
            for(int j=1;j<m;j++){
                if(dp[i][j]==1)
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
            }
        }
        
        int count =0;
        for(int i= 0;i<n;i++){
            for(int j =0;j<m;j++){
                count +=dp[i][j];
            }
        }
        return count;
    }
};


/*


  0 1 1 1 
  1 1 1 1 
  0 1 1 1

  0 1 1 1
  1 1 2 2
  0 1 2 3


*/
