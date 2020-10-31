//Brute Force way is to keep a left and right pointer and calculate all possible substrings and then check if it's a palindrome
//also keep an ans count and keep updating it

//Optimal way is to use 2d DP array where dp[i][j] denotes i-> starting char,j->ending char hence j>=i so we'll just fill half of the array
//So if we visualise the diagonal and every cell to the right of the diagonal will be like base case

#include<bits/stdc++.h>
using namespace std;


   string longestPalindrome(string str) {
	int n = str.size();
	if(n==0 || n==1)
        return str;
    int dp[n][n];
	int i=0;
	int j=0;
	
	int count = 1;
    pair<int,int> ans;//stores the starting and ending indices of answer string
    //filling the diagonal
    for(i=0,j=0;i<n,j<n;i++,j++){
		dp[i][j] = 1;
	}
	//filling the next cell to the digonal
	for(i=0,j=1;i<n-1,j<n;i++,j++){
		if(str[i] == str[j]){
			dp[i][j] = 1;
            ans.first = i;
            ans.second = j;
        }
		else
			dp[i][j] = 0;
	}
	//note that we are filling the matrix diagonally 
	//filling the rest of the matrix
	
	int k=2;
	while(k<n){
		j=k;
			for(i=0;j<n;i++,j++){
				if(str[i]==str[j] && dp[i+1][j-1]){
					dp[i][j] = 1;
					if(j-i+1 > count){
						count = j-i+1;
						ans.first = i;
						ans.second = j;
					}
				}
				else
					dp[i][j] = 0;
			}
		k++;	
	}
	string final = str.substr(ans.first,ans.second-ans.first+1);
return final;
}


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	string str;
	cin>>str;
	string result = longestPalindrome(str);
	cout<<result;
	return 0;
}