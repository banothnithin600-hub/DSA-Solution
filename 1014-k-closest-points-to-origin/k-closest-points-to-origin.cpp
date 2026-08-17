class Solution {
public:
    double power(double x2,double y2){
        double x1=0;
        double y1=0;
        return sqrt(pow(y2-y1,2)+pow(x2-x1,2));
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        int n = points.size();

        vector<pair<double,int>> dist;

        for(int i=0;i<n;i++){
            double x2 = points[i][0];
            double y2 = points[i][1];
            dist.push_back({power(x2,y2),i});
        }

        sort(dist.begin(),dist.end());

        int i=0;
        while(k--){
            ans.push_back(points[dist[i].second]);
            i++;
        }

        return ans;
    }
};