class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            int currHeight = (i == n ? 0 : heights[i]);

            while (!st.empty() && currHeight < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();

                int right = i;
                int left = st.empty() ? -1 : st.top();

                int width = right - left - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n =matrix.size();
        int m = matrix[0].size();
        vector<int> height(m, 0);
int maxarea = 0;

for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
        if(matrix[i][j] == '1')
            height[j]++;
        else
            height[j] = 0;
    }
    maxarea = max(maxarea, largestRectangleArea(height));
}
  return maxarea;
    }
};