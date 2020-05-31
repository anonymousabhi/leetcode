class Solution {
public:
    vector<int> countBits(int num) {
        
        vector<int> v;
        v.push_back(0);
        
        
        if(num==0)
            return v;
        v.push_back(1);
        if(num==1)
            return v;
        for(int i=2;i<=num;i++)
        {
            v.push_back(v[i/2]+i%2);
        }
        
        
        return v;
    }
};



/*
8 1000
7 0111
6 0110
5 0101
4 0100
3 0011
2 0010
1 0001
0 0000
*/
