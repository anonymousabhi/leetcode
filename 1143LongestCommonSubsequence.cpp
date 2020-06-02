class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int r = text2.size()+1;
        int c = text1.size()+1;
        int dp[r][c];
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                dp[i][j] = 0;
            }
        }
        
        
        
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                
                //cout<<text2[i-1]<<" "<<text1[j-1]<<endl;
                if(text2[i-1]==text1[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                
            }
        }
        
        return dp[r-1][c-1];
        
    }
};
/*

  abcde
 000000
a011111
c011222
e011223
*/
