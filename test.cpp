#include<bits/stdc++.h>
using namespace std;

int c=0;
int fs(string s1,string s2,int ps1,int ps2,vector<vector<int>> &data){int i=ps2;
  
    if(data[ps1][ps2]==-1){while(i<s2.length()&&s2[i]!=s1[ps1])i++;
                          
                        if(i==s2.length())data[ps1][ps2]=1;
                           else{
                               data[ps1][ps2]=min(fs(s1,s2,ps1+1,ps2,data),1+fs(s1,s2,ps1+1,i+1,data));}
                           
                          
                          
        
    }
    c++;
    return(data[ps1][ps2]);
}
int solve(string S,string V)
{
	// Write your code here.
    int n=S.length(),m=V.length();
    vector<vector<int>> data(n+1,vector<int>(m+1));
    for(int i=0;i<n;i++){data[i].assign(m+1,-1);data[i][m]=1;}data[n].assign(m+1,100000);
    return(fs(S,V,0,0,data));
}


int main()
{
    string S,V;
    cin>>S>>V;
    cout<<solve(S,V)<<endl;
    cout<<c;

    return 0;
}