class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        if(n == 0 || n == 1)
            return true;
        
        string str;

        for(char c : s){
            if(isalnum(c)) {
                if((c >= 65 and c <= 90))
                    c=c+32; // if char is Upper, convert to lower
                str+=c;
            }        
        }
    
        int left = 0;
        int right = str.length()-1;
        while(left < right)
            if(str[left++] != str[right--])
                return false;
        return true;
        
    }
};