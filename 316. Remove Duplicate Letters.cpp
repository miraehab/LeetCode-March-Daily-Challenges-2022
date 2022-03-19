class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> letters(26, 0);
        vector<bool> visited(26, 0);
        for(int i = 0; i < s.length(); ++i){
            letters[s[i]-97]++;
        }
        stack<char> tmp;
        for(int i = 0; i < s.length(); ++i){
            if(tmp.size() == 0) tmp.push(s[i]), letters[s[i]-97]--, visited[s[i]-97] = 1;
            else{
                 if(!visited[s[i]-97]){
                    while(tmp.size() != 0 && tmp.top() > s[i] && letters[tmp.top()-97] > 0){
                        visited[tmp.top()-97] = 0;
                        tmp.pop();
                    }
                    tmp.push(s[i]);
                    visited[tmp.top()-97] = 1;
                 }
                letters[s[i]-97]--;
            }
        }
        string ans = "";
        while(!tmp.empty()){
            ans+=tmp.top();
            tmp.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};