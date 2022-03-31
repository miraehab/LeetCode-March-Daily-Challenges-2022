class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int maxi = 0, sum =0;
        for(int i = 0; i<nums.size(); ++i){
            sum+=nums[i];
            maxi = max(maxi, nums[i]);
        }
        int l = maxi, r = sum;
        int ans = r;
        while(l <= r){
            int mid = l + ((r-l)/2);
            int sub_array = 1, current_sum = 0;
            for(int n : nums){
                current_sum+=n;
                if(current_sum > mid){
                    ++sub_array;
                    current_sum = n;
                }
            }
            if(sub_array <= m){
                ans = mid;
                r = mid-1;
            }else{
                l = mid +1;
            }
        }
        return ans;
    }
};