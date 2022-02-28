class Solution {
public:
    int compareVersion(string version1, string version2) {
        string tmp;
        int size = 
            max(count(version1.begin(), version1.end(), '.')+1, count(version2.begin(), version2.end(), '.')+1), 
        index = 0;
        vector<int> v1(size, 0);
        vector<int> v2(size, 0);
        for(int i = 0; i<version1.length(); i++){
            if(version1[i] == '.'){
                int t = stoi(tmp);
                v1[index] = t;
                tmp = "";
                index++;
            }else{
                tmp += version1[i];
            }
            if(i == version1.length()-1){
                int t = stoi(tmp);
                v1[index] = t;
            }
        }
        tmp = ""; index = 0;
        for(int i = 0; i<version2.length(); i++){
            if(version2[i] == '.'){
                int t = stoi(tmp);
                v2[index] = t;
                tmp = "";
                index++;
            }else{
                tmp += version2[i];
            }
            if(i == version2.length()-1){
                int t = stoi(tmp);
                v2[index] = t;
            }
        }
        for(int i = 0; i<size; i++){
            if(v1[i] > v2[i]){
                return 1;
            }else if(v1[i] < v2[i]){
                return -1;
            }
        }
        return 0;
    }
};