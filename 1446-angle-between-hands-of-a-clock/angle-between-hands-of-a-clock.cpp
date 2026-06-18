class Solution {
public:
    double angleClock(int hour, int minutes) {
        double deg_1_mint=6.0;
        double hour_deg=(minutes/12.0)*6.0;
        double ans = minutes*deg_1_mint-hour*30-hour_deg;
        ans=abs(ans);
        ans=min(ans,360-ans);
        return ans;
    }
};