class Solution {
public:
    bool divisorGame(int N) {
        
        bool arr[1001];
        arr[1]=false;
        arr[2]=true;
        
        if(N<3)
            return arr[N];
        
        for(int i=3;i<=N;i++)
        {
            arr[i]=false;
            for(int j=1;j<i;j++){
                if(i%j==0){
                    if(arr[i-j]==false){
                        arr[i]=true;
                        break;}
                }
            }
        }
        return arr[N];
        
    }
};

/*


        1  2. 3. 4.    5. 6 
        F. T. F. T.    F. T  
        
        6 1 2 3

*/
