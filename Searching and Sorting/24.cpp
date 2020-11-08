#include<bits/stdc++.h>
using namespace std;


bool check(long long positions[],long long mid,int c ,int n)
{
	int count=1;
	int last_posi=positions[0];

	for(int i=1;i<n;i++)
	{
		if(positions[i]-last_posi>=mid){
			count++;
			last_posi=positions[i];
		}
		if(c==count)
			return true;

	}
	return false;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,c;
		cin>>n>>c;
		long long positions[n];
			for(int i=0;i<n;i++)
				cin>>positions[i];
		sort(positions,positions+n);
		int ans=-1;
	
        long long start=0;
		long long end=positions[n-1]-positions[0];

		while(start<=end)
		{
			long long mid=start + (end-start)/2;
			if(check(positions,mid,c,n))
			{
				ans=mid;
				start=mid+1;
			}
			else
			{
				end=mid-1;
			}
		}
		cout<<ans<<endl;
	}	

	return 0;
}