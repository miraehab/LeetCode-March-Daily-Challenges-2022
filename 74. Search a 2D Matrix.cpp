class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size()-1;
        for(int i = 0; i<matrix.size(); ++i){
            if(target <= matrix[i][n]){
                int l = 0, r = n;
                while(l <= r){
                    int mid = l + ((r-l)/2);
                    if(matrix[i][mid] == target) return true;
                    else if(target < matrix[i][mid]) r = mid -1;
                    else l = mid + 1;
                }
                return false;
            }
        }
        return false;
    }
};