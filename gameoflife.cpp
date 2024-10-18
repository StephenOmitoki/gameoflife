#include <iostream>
#include <vector>

using namespace std;


const int ROWS = 10;
const int GRID_COLS = 10;  
vector<vector<int>> grid(ROWS, vector<int>(GRID_COLS, 0));


void readInitialConfig();
void displayGrid();
void updateGrid();
int countLiveNeighbors(int x, int y);  // Count neighbors


void readInitialConfig() {
    int x, y;
    cout << "Enter the coordinates of live cells (enter -1 -1 to stop):\n";
    while (true) {
        cin >> x >> y;  // Get input from user
        if (x == -1 && y == -1) {
            break;  // Stop when user enters -1 -1
        }
        if (x >= 0 && x < ROWS && y >= 0 && y < GRID_COLS) {
            grid[x][y] = 1;  // Mark cell as alive
        }
    }
}


void displayGrid() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < GRID_COLS; ++j) {
            if (grid[i][j] == 1) {
                cout << "O ";  // Live cell
            } else {
                cout << ". ";  // Dead cell
            }
        }
        cout << endl;
    }
    cout << endl;
}

// Update the grid to the next generation
void updateGrid() {
    vector<vector<int>> nextGrid(ROWS, vector<int>(GRID_COLS, 0));

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < GRID_COLS; ++j) {
            int liveNeighbors = countLiveNeighbors(i, j);

            if (grid[i][j] == 1) {
                if (liveNeighbors < 2 || liveNeighbors > 3) {
                    nextGrid[i][j] = 0;  // Cell dies
                } else {
                    nextGrid[i][j] = 1;  // Cell lives
                }
            } else {
                if (liveNeighbors == 3) {
                    nextGrid[i][j] = 1;  // Cell is born
                }
            }
        }
    }

    grid = nextGrid;  // Update the grid
}

// Count live neighbors for a cell
int countLiveNeighbors(int x, int y) {
    int liveCount = 0;

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;  // Skip the cell itself

            int newX = x + i;
            int newY = y + j;

            if (newX >= 0 && newX < ROWS && newY >= 0 && newY < GRID_COLS && grid[newX][newY] == 1) {
                liveCount++;  // Add to the count if it's alive
            }
        }
    }

    return liveCount;
}
