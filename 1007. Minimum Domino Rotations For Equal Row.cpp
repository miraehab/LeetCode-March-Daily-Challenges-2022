class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
       int top = tops[0], bottom = bottoms[0], ans = 0;
        int miss_T_1 = 0, miss_B_1 = 0, miss_T_2 = 0, miss_B_2 = 0;
        bool bool_top = true, bool_bottom = true;
        for(int i = 0; i < tops.size(); ++i){
            if((tops[i] != top && bottoms[i] != top)){
                bool_top = false;
            }
            
            if((bottoms[i] != bottom && tops[i] != bottom)){
                bool_bottom = false;
            }
            
            if(tops[i] != top) ++miss_T_1;
            if(bottoms[i] != top) ++miss_B_1;
            
            if(tops[i] != bottom) ++miss_T_2;
            if(bottoms[i] != bottom) ++miss_B_2;
        }
        if(bool_top == false && bool_bottom == false) return -1;
        return min({miss_T_1, miss_T_2, miss_B_1, miss_B_2});
    }
};