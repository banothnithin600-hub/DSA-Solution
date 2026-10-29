class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        for(int i=0;i<arr.size();i++){ 
            for(int j=arr.size() - 1;j<arr.size();j--){
                if(i != j && arr[i] == 2 * arr[j]){
                    return true;
                }
            }
        }
        return false;
    }
};