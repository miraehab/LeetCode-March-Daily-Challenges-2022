class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> nums;
        int tmp = 0;
        for(int i = 0; i<pushed.size(); ++i){
            nums.push(pushed[i]);
            while(nums.size() > 0 && nums.top() == popped[tmp]){
                nums.pop();
                ++tmp;
            }
        }
        if(nums.size() == 0) return true;
        else return false;
    }
};