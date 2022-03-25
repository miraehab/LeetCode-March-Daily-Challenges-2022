class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<int> diff;
        int sum = 0;
        for(int i = 0; i < costs.size(); ++i){
            diff.push_back(costs[i][1]-costs[i][0]);
            sum+=costs[i][0];
        }
        sort(diff.begin(), diff.end());
        for(int i = 0; i < costs.size()/2; ++i){
            //B-A+A = B
            sum+=diff[i];
        }
        return sum;
    }
};