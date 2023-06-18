class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int maxDistance = mainTank * 10; // Calculate maximum distance based on fuel in the main tank
    int remainingFuel = mainTank; // Initialize remaining fuel in the main tank

    while (remainingFuel >= 5) {
        if (additionalTank >= 1) {
            remainingFuel -= 5; // Deduct 5 liters from the main tank
            additionalTank -= 1; // Deduct 1 liter from the additional tank
            remainingFuel += 1; // Transfer 1 liter from the additional tank to the main tank
            maxDistance += 10; // Increase the maximum distance by 10 km
        } else {
            break; // Break the loop if there is not enough fuel in the additional tank
        }
    }

    return maxDistance;
    }
};