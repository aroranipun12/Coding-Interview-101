#include <iostream>
#include<unordered_map>
#include<string>
using namespace std;
//ijj oooo qrst vgfd ijkl aahad efgh nop vgfd oooo 
int main() {
    // Write your code here
    unordered_map<string,int> m;
    string s,ss="";
    cin>>s;
    int c=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==' ')
        {
        	cout<<"lodu";
        	m[ss]++; ss="";c++;}
        else
        {
          ss+=s[i];  
        }
    }
    int l=0;
    for(auto i=m.begin();i!=m.end();i++)
    {
        if(i->second==0||i->second==1)
        { l++;continue;}
        else
            cout<<i->first<<" "<<i->second<<endl;
        
    }
    if(l==c)
        cout<<-1<<endl;
}