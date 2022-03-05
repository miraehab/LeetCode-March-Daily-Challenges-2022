class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        if(nums.size() == 1) return nums[0];
        int maxi = nums[0];
        vector<pair<int, int>> U_nums;
        
        sort(nums.begin(), nums.end());
        maxi = nums[nums.size()-1];
        for(int i = 0; i <= nums[nums.size()-1]; i++){
            U_nums.push_back(make_pair(i, count(nums.begin(), nums.end(), i)*i));
        }
        
        vector<int> dp(maxi+1, 0);
        dp[1] = U_nums[1].second;

        for(int i = 2; i < dp.size(); i++){
            dp[i] = max(U_nums[i].second + dp[i-2], dp[i-1]);
        }
        return dp[maxi];
    }
};