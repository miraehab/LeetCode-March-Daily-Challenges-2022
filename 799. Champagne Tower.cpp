class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> rows;
        for(int i = 0; i<=query_row; i++){
            vector<double> tmp(i+1,0);
            if(i == 0){
                tmp[i] = poured;
            }else{
                for(int j = 0; j<i; j++){
                    if((rows[i-1][j]-1)/2 > 0)tmp[j] = tmp[j] + (rows[i-1][j]-1)/2;
                    if((rows[i-1][j]-1)/2 > 0) tmp[j+1] = tmp[j+1] + (rows[i-1][j]-1)/2;
                }
            }
            rows.push_back(tmp);
        }
        if(rows[query_row][query_glass] > 1){
            return double(1);
        }else if(rows[query_row][query_glass] < 0){
            return double(0);
        }else{
            return rows[query_row][query_glass];
        }
    }
};