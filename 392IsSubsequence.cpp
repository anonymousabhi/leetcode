class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        
        int dp[s.size()+1][t.size()+1];
        for(int i = 0; i < s.size()+1; i++){
            for(int j = 0 ;j<t.size()+1;j++){
                dp[i][j] = 0;
            }
        }
        int m =0;
        for(int i = 1; i<s.size()+1; i++){
            for(int j = 1 ;j<t.size()+1;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
                m = max(m,dp[i][j]);
            }
        }
        
        for(int i = 0; i < s.size()+1; i++){
            for(int j = 0 ;j<t.size()+1;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        
        
        return (m==s.size())?true:false;
        
        
    }
};

/*
  "" a h b g d c 
"" 0 0 0 0 0 0 0  
a  0 1 1 1 1 1 1
b  0 0 0 2 2 2 2 
c  0 0 0 2 2 2 3


*/
