class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> indexes(26, 0);
        for(int i = 0; i < s.length(); ++i){
            indexes[s[i] - 'a'] = i;
        }
        int j = 0, a = 0;
        vector<int> result;
        for(int i = 0; i < s.length(); ++i){
            j = max(j, indexes[s[i]-'a']);
            if(i == j){
                result.push_back(i - a + 1);
                a = i + 1;
            }
        }
        return result;
    }
};