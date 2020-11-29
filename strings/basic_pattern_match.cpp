#include<bits/stdc++.h>
using namespace std;

int* getlps(string pattern){
	int l = pattern.length();

	int* lps = new int[l];
	lps[0] = 0;
	int i = 1;
	int j = 0; 
	while(i < l){
		if(pattern[i] == pattern[j]){
			lps[i] = j + 1;
			j++;
			i++;
		}
		else{
			if(j != 0){
				j = lps[j-1];
			}
			else{
				lps[i] = 0;
				i++;
			}
		}
	}
return lps;
}

//time complexity O(n*m) (kaafi bekaar approach h bas interview m basic se start krna)
bool isMatch(string str,string pattern){
    int n = str.length();
    int m = pattern.length();

    for(int i=0;i<= n-m ;i++){
        bool isFound = true;
            for(int j=0;j<m;j++){
                if(str[i+j] != pattern[j]){
                    isFound = false;
                    break;
                }
            }
            if(isFound == true)
                return true;
    }
return false;
}

int main(){
    string a;
    cin>>a;
    string b;
    cin>>b;

    cout<<isMatch(a,b);
return 0 ;
}