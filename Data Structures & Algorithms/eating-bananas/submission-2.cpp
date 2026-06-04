class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int speed=1;
        while(true){
            long long totaltime=0;
            for(int pile:piles){
                totaltime+=((pile+speed-1)/speed);
            }
            if(totaltime<=h) return speed;
            speed++;
        }
    }
};
