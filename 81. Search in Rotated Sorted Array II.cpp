class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0, next = 1;
        if(is_sorted(nums.begin(), nums.end())){
            int l = 0, r = nums.size()-1;
            while(l <= r){
                int mid = l + ((r-l)/2);
                if(nums[mid] == target) return true;
                if(target < nums[mid]) r = mid -1;
                else l = mid+1;
            }
        }else{
            while(next < nums.size()-1 && nums[start] <= nums[next]){
                ++start;
                ++next;
            }
            int l1, l2, r1, r2;
            if(next < nums.size()){ 
                l1 = 0, r1 = start, l2 = next, r2 = nums.size()-1;
                if(target >= nums[l1]){
                    while(l1 <= r1){
                        int mid = l1 + ((r1-l1)/2);
                        if(nums[mid] == target) return true;
                        if(target < nums[mid]) r1 = mid -1;
                        else l1 = mid+1;
                    }
                }else{
                   while(l2 <= r2){
                        int mid = l2 + ((r2-l2)/2);
                        if(nums[mid] == target) return true;
                        if(target < nums[mid]) r2 = mid -1;
                        else l2 = mid+1;
                    } 
                }
            }
        }
        return false;
    }
};