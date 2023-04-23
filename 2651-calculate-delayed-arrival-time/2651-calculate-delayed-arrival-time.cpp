class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        return arrivalTime + delayedTime < 24 ? arrivalTime + delayedTime : arrivalTime + delayedTime - 24;
    }
};