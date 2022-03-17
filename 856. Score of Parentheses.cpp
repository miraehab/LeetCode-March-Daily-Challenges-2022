class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> tmp;
        int score = 0;
        for(int i = 0; i<s.length(); ++i){
            if(s[i] == '('){
                tmp.push(score);
                score = 0;
            }else{
                score = tmp.top() + max(2*score, 1);
                tmp.pop();
            }
        }
        return score;
    }
};