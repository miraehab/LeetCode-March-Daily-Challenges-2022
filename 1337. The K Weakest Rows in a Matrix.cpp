class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        multiset <pair<int, int>> counts;
        for(int i = 0; i < mat.size(); ++i){
                counts.insert(make_pair(count(mat[i].begin(), mat[i].end(),1), i));
            
        }
        int tmp = 0;
        vector<int> ans;
        for(auto i = counts.begin(); tmp<k; i++){
            ans.push_back((i)->second);
            ++tmp;
        }
        return ans;
    }
};