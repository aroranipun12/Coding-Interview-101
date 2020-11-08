long long merge(long long arr[],int left,int mid,int right)
{
	int i=left,j=mid,k=0;
	long long temp[right-left+1];
	long long count=0;

	while(i<mid && j<=right)
	{
		if(arr[i]<=arr[j])
			temp[k++]=arr[i++];
		else{
			temp[k++]=arr[j++];
			count+=mid-i;
		}
	}
	while(i<mid)
	{
		temp[k++]=arr[i++];
	}
	while(j<=right)
	{
		temp[k++]=arr[j++];
	}

	for(int i=left,k=0;i<=right;i++,k++)
	{
		arr[i]=temp[k];
	}
return count;
}
long long merge_sort(long long arr[],int left ,int right)
{
	long long count=0;
		if(right > left)
		{
			int mid=(right+left)/2;
			
			long long leftC=merge_sort(arr,left,mid);
			long long rightC=merge_sort(arr,mid+1,right);
			long long myC=merge(arr,left,mid+1,right);
			
			return leftC + rightC + myC;
		}
	return count;
}

long long getInversions(long long A[], int n)
{
	long long ans=merge_sort(A,0,n-1);
	
	return ans;
}
