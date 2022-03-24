class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int start = 0, end = people.size()-1, length = people.size(), ans = 0, flag =people.size();
        sort(people.begin(), people.end());
        while(start != end && flag > 0){
            if(people[start]+people[end] > limit) --end, --flag;
            else if(people[start]+people[end] <= limit){
                ++ans;
                ++start;
                --end;
                length-=2;
                flag-=2;
            }
        }
        return ans + max(0, length);
    }
};