class Solution {
public:
    bool isValid(string s) {
        stack<char> bs;
        for(int i = 0; i<s.length(); ++i){
            if(s[i] == '(') bs.push('(');
            else if(s[i] == '{') bs.push('{');
            else if(s[i] == '[') bs.push('[');
            else if(s[i] == ')' && bs.size() != 0 && bs.top() == '('){
                bs.pop();
            }else if(s[i] == '}' && bs.size() != 0 && bs.top() == '{'){
                bs.pop();
            }else if(s[i] == ']' && bs.size() != 0 && bs.top() == '['){
                bs.pop();
            }else{
              return false;  
            } 
        }
        if(bs.size() == 0) return true;
        else return false;
    }
};