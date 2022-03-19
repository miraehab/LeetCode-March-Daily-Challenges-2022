class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        long long j;
        if(nums.size() > 0) j = nums[0];
        vector<long long> tmp;
        vector<vector<long long>> to_print;
        vector<string> result;
        for(int i =0 ;i<nums.size(); i++){
            if(nums[i] == j){
                tmp.push_back(nums[i]);
                j++;
            }else{
                to_print.push_back(tmp);
                tmp.clear();
                tmp.push_back(nums[i]);
                j = (long long)nums[i]+1;
            }
            if(nums.size()-1 == i)to_print.push_back(tmp);
        }
        for(int i = 0; i<to_print.size(); i++){
            if(to_print[i].size() == 1){
                result.push_back(to_string(to_print[i][0]));
            }else{
                string s = to_string(to_print[i].front()) + "->" + to_string(to_print[i].back());
                result.push_back(s);
            }
        }
        return result;
    }
};