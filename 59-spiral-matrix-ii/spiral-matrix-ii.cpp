class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> ans(n, vector<int>(n));

        int sr = 0;
        int er = n - 1;
        int sc = 0;
        int ec = n - 1;

        int k = 1;

        while (sr <= er && sc <= ec) {

            // Step 1: left to right
            for (int j = sc; j <= ec; j++) {
                ans[sr][j] = k++;
            }
            sr++;

            // Step 2: top to bottom
            for (int i = sr; i <= er; i++) {
                ans[i][ec] = k++;
            }
            ec--;

            // Step 3: right to left
            for (int j = ec; j >= sc; j--) {
                ans[er][j] = k++;
            }
            er--;

            // Step 4: bottom to top
            for (int i = er; i >= sr; i--) {
                ans[i][sc] = k++;
            }
            sc++;
        }

        return ans;
    }
};