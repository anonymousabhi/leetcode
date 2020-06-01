class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        
        int n=A.size();
        
        int ans[n][n];
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){   
                ans[i][j]=A[i][j];
            }
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                if(j==0){
                    ans[i][j] = A[i][j] + min(ans[i+1][j],ans[i+1][j+1]);
                }
                else if(j==n-1){
                    ans[i][j] = A[i][j] + min(ans[i+1][j],ans[i+1][j-1]);
                }
                else{
                    ans[i][j] = A[i][j] + min(ans[i+1][j],min(ans[i+1][j-1],ans[i+1][j+1]));
                }
            }
        }
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
        
        int temp=INT_MAX;
        for(int i=0;i<n;i++)
            temp = min(temp,ans[0][i]);
        
        return temp;
    }
};


/*

[1,2,3]
[4,5,6]
[7,8,9]

[12,13,15]
[11,12,14]
[7,8,9]


*/
