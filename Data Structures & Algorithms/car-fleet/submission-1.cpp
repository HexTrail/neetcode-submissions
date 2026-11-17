class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> cars;
        // Pair position and speed together
        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end()); //sorts by the first of the pair i.e. the position
        stack <double> s;
        for(int i=n-1;i>=0;i--){
            double timeReq = (double)(target- cars[i].first)/cars[i].second;
            if(s.empty() || timeReq > s.top()) s.push(timeReq);
        }
        return s.size();
    }
};
