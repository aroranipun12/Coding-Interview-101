//leetcode 20

class Solution {
public:
    bool balance(string str){
    stack<char> s;
    char x;
    for(int i=0;i<str.length();i++){
        if(str[i] == '{' || str[i] == '[' || str[i] == '('){
            s.push(str[i]);//push all opening brackets
            continue;
        }

        //if not opening brackets

        //stack should not be empty at this point
        if(s.empty())
            return false;
        //must be closing brackets
        switch(str[i]){
            case '}':
                //check kro ki pichla wala iska opening ke alawa kuch aur toh ni h
                x = s.top();
                s.pop();
                if(x == '[' || x == '(')
                    return false;
                break;
            case ']':
                x = s.top();
                s.pop();
                if(x == '{' || x == '(')
                    return false;
                break;
            case ')':
                x = s.top();
                s.pop();
                if(x == '[' || x == '{')
                    return false;
                break;
        }
    }
    return s.empty();//agar empty h toh balanced h
}
    bool isValid(string s) {
        if(s.length() == 0)
            return true;
        if(s.length() == 1)
            return false;
        return balance(s);
    }
};