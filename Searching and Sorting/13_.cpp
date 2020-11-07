//to handle negative numbers sort the input and and put i from 0 to n-2 and find other two elements using two pointer like this
/*a) Initialize other two elements as corner elements of subarray
        arr[i+1..n-1], i.e., j = i+1 and k = n-1
     b) Move j and k toward each other until they meet, i.e., while (j = remain_sum), then do k--

            // Else for current i and j, there can (k-j) possible third elements
            // that satisfy the constraint.
            (ii) Else Do ans += (k - j) followed by j++ */

int countTriplets(int arr[], int n, int sum) 
{ 
    // Sort input array 
    sort(arr, arr+n); 

    // Initialize result 
    int ans = 0; 

    // Every iteration of loop counts triplet with 
    // first element as arr[i]. 
    for (int i = 0; i < n - 2; i++) 
    { 
        // Initialize other two elements as corner elements 
        // of subarray arr[j+1..k] 
        int j = i + 1, k = n - 1; 

        // Use Meet in the Middle concept 
        while (j < k) 
        { 
            // If sum of current triplet is more or equal, 
            // move right corner to look for smaller values 
            if (arr[i] + arr[j] + arr[k] >= sum) 
                k--; 

            // Else move left corner 
            else
            { 
                // This is important. For current i and j, there 
                // can be total k-j third elements. 
                ans += (k - j); 
                j++; 
            } 
        } 
    } 
    return ans; 
} 


//---------------------------------------------------


//only works for positive and distinct numbers
long long countTriplets(long long arr[], int n, long long sum)
{
    sort(arr,arr+n);
    int i=2;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    while(i<n && arr[i]+arr[i-1]+arr[i-2]<sum){
        i++;
    }
    //Now just select 3 elements out of this subarray(from 0th to i-1th)
    long long ans = (i*(i-1)*(i-2))/6;
return ans;
}   