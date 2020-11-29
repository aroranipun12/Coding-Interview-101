//time O(n) + O(m)
//space O(m)
//returns the starting index of the pattern found in text , otherwise returns -1

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

int kmpSearch(string text , string pattern){
	int lenText = text.length();
	int lenPat = pattern.length();

	int i = 0;
	int j = 0;

	int* lps = getlps(pattern);
	while(i<lenText && j<lenPat){
		if(text[i] == pattern[j]){
			i++;
			j++;
		}
		else{
			if(j != 0){
				j = lps[j-1];
			}
			else{
				i++;
			}
		}
	}
	if(j == lenPat){
		return i-lenPat;
	}
return -1;
}

int main(){
	string s,p;
	cin>>s;
	cin>>p;

	cout<<kmpSearch(s,p)<<endl;

	return 0;
}