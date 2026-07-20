class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        //Logical :- mat[i/n][i%n]=original[i];
        vector<vector<int>>mat(m,vector<int>(n));
        if(m*n!=original.size()){
            return {};
        }
        for(int i=0;i<n*m;i++){
            mat[i/n][i%n]=original[i];
        }
        return mat;
    }
};