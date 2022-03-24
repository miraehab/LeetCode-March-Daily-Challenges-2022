class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans;
        while(target > startValue){
            ++ans;
            if(target%2 == 1){
                ++target;
            }else{
                target/=2;
            }
        }
        return ans + startValue - target;
    }
};