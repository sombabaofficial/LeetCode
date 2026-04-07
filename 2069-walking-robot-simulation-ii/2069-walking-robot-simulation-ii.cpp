class Robot {
private:
    int w, h, x, y, dir;
    vector<string> d = {"East", "North", "West", "South"};

public:
    Robot(int width, int height) {
        w = width; h = height;
        x = 0; y = 0; dir = 0; 
    }
    
    void step(int num) {
        int cycle = 2 * (w + h) - 4;
        num %= cycle; 

        if (num == 0) {
            if (x == 0 && y == 0) dir = 3; 
            return;
        }

        while (num > 0) {
            if (dir == 0) { 
                int move = min(num, w - 1 - x);
                x += move; num -= move;
                if (move == 0) dir = 1; 
            } else if (dir == 1) { 
                int move = min(num, h - 1 - y);
                y += move; num -= move;
                if (move == 0) dir = 2;
            } else if (dir == 2) { 
                int move = min(num, x);
                x -= move; num -= move;
                if (move == 0) dir = 3;
            } else { // South
                int move = min(num, y);
                y -= move; num -= move;
                if (move == 0) dir = 0;
            }
        }
    }
    
    vector<int> getPos() { return {x, y}; }
    string getDir() { return d[dir]; }
};