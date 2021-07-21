#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	
	vector<int> a= {1,2,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,5,5,5,5,6,6,7,7,7,7,8,8,9};
	int n =a.size();
	
	int low = 0;
	int high = n-1;
	int mid;
	int ans =2;
    while(low<high){
       mid = (low+high)/2; 
       if(a[mid]<ans){
           low=mid+1;
       }else{
           high=mid;
           
       }
       cout<<low<<" "<<high<<endl;
    }cout<<"Start is "<<low<<"   "<<a[low]<<endl;
	
	
	
	low = 0;
	high = n-1;
	while(low<high){
      mid = (low+high)/2;
      if(a[mid]<=ans){
          low=mid+1;
      }else{
          high=mid;
           
      }
      cout<<low<<" "<<high<<endl;
    }
    if(low==n-1)
    cout<<"End is "<<low<<"   "<<a[low]<<endl;
    else
    cout<<"End is "<<low-1<<"   "<<a[low-1]<<endl;
    
	return 0;
}
