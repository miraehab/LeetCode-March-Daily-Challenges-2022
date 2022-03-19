class Solution {
public:
    string simplifyPath(string path) {
        string tmp = "";
        deque<string> result;
        for(int i = 0; i <path.length(); ++i){
                if(path[i] == '/' || i == path.length()-1){
                    if(path[i] != '/') tmp+=path[i];
                    if(tmp == ".." && result.size() > 0) result.pop_back();
                    else if(tmp.length() > 0 && tmp != "." && tmp != "..") 
                        result.push_back(tmp);
                    tmp="";
                }else if(path[i] != '/'){
                    tmp+=path[i];
                }
        }
        string ans = "/";
        for(int i = 0; i<result.size(); ++i){
            ans.append(result[i]);
             if(i != result.size()-1) ans+="/";
        }
        return ans;
    }
};