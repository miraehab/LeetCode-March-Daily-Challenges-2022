class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> ind;
        vector<int> remove;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == '('){
                ind.push(i);
            }else if(s[i] == ')'){
                if(ind.size() == 0){
                    remove.push_back(i);
                }else{
                    ind.pop();
                }
            }
        }
        while(!ind.empty()){
            remove.push_back(ind.top());
            ind.pop();
        }
        sort(remove.begin(), remove.end());
        string tmp = "";
        int index = 0;
        for(int i = 0; i<s.length(); ++i){
            if(index < remove.size() && i == remove[index]) ++index;
            else{
                tmp+=s[i];
            }
        }
        return tmp;
    }
};