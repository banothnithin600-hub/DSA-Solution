class Solution {
public:
   void dsf(vector<vector<int>>& image, int sr, int sc, int initialcolor,int newcolor){
    int n  = image.size();//total no. of rows
        int m = image[0].size();//total no.colums
        if(sr<0 || sc<0 || sr>=n || sc>=m){//outside the grid ,means out of boundary
            return;
        }
        
        if(image[sr][sc]!=initialcolor) return;//if the cell you landed is not of initial color

        image[sr][sc]=newcolor;
        //down
        dsf(image,sr+1,sc,initialcolor,newcolor);
        //left
        dsf(image,sr,sc-1,initialcolor,newcolor);
        //right
        dsf(image,sr,sc+1,initialcolor,newcolor);
        //up
        dsf(image,sr-1,sc,initialcolor,newcolor);
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
       dsf(image,sr,sc,image[sr][sc],color);
       return image;
    }
};