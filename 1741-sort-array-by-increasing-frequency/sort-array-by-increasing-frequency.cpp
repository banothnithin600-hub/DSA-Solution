class Solution {
public:

    struct compare {
        bool operator()(pair<int,int>& p1, pair<int,int>& p2) {

            if(p1.first == p2.first) {
                return p1.second < p2.second;
            }

            return p1.first > p2.first;
        }
    };

    vector<int> frequencySort(vector<int>& nums) {

        unordered_map<int,int> freq;

        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            compare
        > pq;

        for(auto x : freq) {
            pq.push({x.second, x.first});
        }

        vector<int> ans;

        while(!pq.empty()) {

            int fre = pq.top().first;
            int val = pq.top().second;

            pq.pop();

            for(int i = 0; i < fre; i++) {
                ans.push_back(val);
            }
        }

        return ans;
    }
};