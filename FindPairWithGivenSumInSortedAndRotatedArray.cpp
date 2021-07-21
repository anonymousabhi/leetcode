#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;

void findSumInRotated(vector<int> a,int pivot, int sum){
    int n  =a.size();
    int low= pivot;
    int high  = (pivot-1)%n;
    
    while(low!=high){
        int temp = a[low]+a[high];
        if(temp<sum)
        low = (low+1)%n;
        else if(temp>sum)
        high = (high-1)%n;
        else{
            cout<<a[low]<<" "<<a[high]<<endl;
            break  ; 
        }
    }

} 


void findSum(vector<int> a, int sum){
    map<int,int> m;
    int n =a.size();
    for(int i=0;i<n;i++){
        if(m[a[i]]==1){
            cout<<"Found pair with "<<a[i]<<" and "<<sum-a[i]<<endl;
            return;
        }else{
            m[sum-a[i]]=1;
        }
    }
}

int findPivot(vector<int> A){
    int n =A.size();
    int l = 0;
    int h = n-1;
    int mid;
    
    while (l<h) {
        mid=(l+h)/2;
        if(A[mid]<A[h]){
            h=mid;
        }else{
            l=mid+1;
        }
    }
    
    return l;
}

//Find a pair that adds up to a sum in a sorted rotated array
int main() {
	//code
	
	vector<int> a2= {7,8,9,10,1,2,3,4,5,6};
	vector<int> a1= {1,2,3,4,5,6,7,8,9,10};
	
	int sum = 13;
	
	//find a sum pair in array
	//findSum(a1,ans);
	
	//If array is sorted and rotated
	int pivot = findPivot(a2);
	cout<<pivot<<endl;
	findSumInRotated(a2,pivot,sum);
	
	
	return 0;
}
