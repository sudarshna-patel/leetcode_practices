// https://leetcode.com/problems/angle-between-hands-of-a-clock/

class Solution {
public:
    double angleClock(int hour, int minutes) {
        // angle for hour hand
        // 12 hours for 360 degrees, so for h angle is (360/12)*h = 30h
        // 60 minutes for 1 hour i.e. 30 degrees so for m angle is (30/60)*m = m/2
        // total angle for hour hand is gonna be 30h + m/2
        
        // angle for minute hand
        // 60 minutes for 360 degree, so for m minutes, (360/60)m = 6m
        
        double hour_angle = hour*30 + double(minutes)/2;
        double minute_angle = 6*minutes;
        
        double diff = abs(hour_angle-minute_angle);
        
        return min(diff, 360-diff);
    }
};

// #include <iostream>
// #include <math.h>
// using namespace std;

// int main() {
//     int hour, minutes;

//     cout << "Enter hour: ";
//     cin >> hour;
//     cout << "Enter minutes: ";
//     cin >> minutes;

//     double hour_angle = hour*30 + double(minutes)/2;
//     double minute_angle = 6*minutes;
    
//     double diff = abs(hour_angle-minute_angle);
    
//     cout << "Angle between clock hands when it's " << hour <<":" << minutes << " is: " << min(diff, 360-diff);
//     return 0;
// }