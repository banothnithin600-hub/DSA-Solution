class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        //a+b+c+d=0 ==>  a+b = -(c+d) ==> we are adding map a+b and we are checking it's freq.. in hashmap -(c+d)
        unordered_map<int,int>m;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                m[nums1[i]+nums2[j]]++;
            }
        }
        int count = 0;
        long long sum = 0;
        for(int i=0;i<nums3.size();i++){
            for(int j=0;j<nums4.size();j++){
                sum=nums3[i]+nums4[j];
                if(m.find((-sum))!=m.end()){
                    count+=m[(-sum)];
                }
            }
        }
        return count;
    }
};