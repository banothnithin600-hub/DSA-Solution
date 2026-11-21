class Solution {
public:
    int va1(vector<int>arr){
        int minl = 0;
        arr[0]=arr[1]+arr[2];
        sort(arr.begin(),arr.end());
        return arr[2]-arr[0];
    }
    int va2(vector<int>arr){
        arr[1]=arr[2]+arr[0];
        sort(arr.begin(),arr.end());
        return arr[2]-arr[0];
    }
    int va3(vector<int>arr){
        arr[2]=arr[0]+arr[1];
        sort(arr.begin(),arr.end());
        return arr[2]-arr[0];
    }
    int minRange(int a, int b, int c) {
       int minl = 0;
       //three case 
        //first inital case
        //second taking two element make that sum
        //return form this which is min val only

        //case 1
        vector<int>arr={a,b,c};
       
        sort(arr.begin(),arr.end());
        int m1 = arr[2]-arr[0];
        //case 1 
        int m2 = va1(arr);
        int m3 = va2(arr);
        int m4 = va3(arr);
        return min({m1,m2,m3,m4});
    }
};