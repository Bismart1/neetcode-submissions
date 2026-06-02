class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>v;
        int s=position.size();
        for(int i=0;i<s;i++){
            v.push_back({position[i],speed[i]});
        }
        sort(v.rbegin(),v.rend());
        double prevt=(double)(target-v[0].first)/v[0].second;
        double currt;
        int fleets=1;
        for(int i=1;i<s;i++){
            currt=(double)(target-v[i].first)/v[i].second;
            if(currt>prevt){
                fleets++;
                prevt=currt;
            }
        }
        return fleets;
    }
};
