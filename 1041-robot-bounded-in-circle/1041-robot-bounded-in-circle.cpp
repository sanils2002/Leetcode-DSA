class Solution {
public:
    bool isRobotBounded(string instructions) {
        // Initial position and direction
        int x = 0, y = 0;
        int dir = 0; // 0: North, 1: East, 2: South, 3: West

        // Loop through the instructions
        for(char instruction : instructions) {
            if(instruction == 'G') {
                // Move 1 unit in the current direction
                if(dir == 0) 
                    y++;
                else if(dir == 1) 
                    x++;
                else if(dir == 2) 
                    y--;
                else if(dir == 3) 
                    x--;
            } 
            else if(instruction == 'L') {
                // Turn 90 degrees to the left
                dir = (dir + 3) % 4;
            }
            else if (instruction == 'R') {
                // Turn 90 degrees to the right
                dir = (dir + 1) % 4;
            }
        }

        // The robot returns to the initial position or is not facing North
        // after one iteration of the instructions
        return (x == 0 && y == 0) || dir != 0;
    }
};