#include<bits/stdc++.h>
using namespace std;

void swap(vector<int> &num,int i1,int i2){
	int temp = num[i1];
	num[i1]=num[i2];
	num[i2]= temp;
return;
}
void nextPermutation(vector<int> &num){
	int n = num.size();
	int i1 = -1;
	int i2 = -1;
	for(int i = n-2;i>=0;i--){
		if(num[i] < num[i+1]){
			i1 = i;
			break;
		}
	}
	if(i1==-1)
		sort(num.begin(),num.end());
	else{
		for(int i=n-1;i>=i1;i--){
			if(num[i] > num[i1]){
				i2 = i;
				break;
			}
		}
		swap(num,i1,i2);
		sort(num.begin()+i1+1,num.end());
	}
}

int main(){
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		vector<int> num(n);
		for(int i=0;i<n;i++){
			cin>>num[i];
		}
		//cout<<num.size();
		nextPermutation(num);
		for(int i=0;i<n;i++){
			cout<<num[i];
		}
	}
	return 0;
}