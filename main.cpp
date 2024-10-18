#include <iostream>
#include <vector>

using namespace std;

extern vector<vector<int>> grid;
extern const int ROWS;
extern const int GRID_COLS;  


void readInitialConfig();
void displayGrid();
void updateGrid();

int main() {
    readInitialConfig();  // Get the starting cells

    char choice = ' ';
    while (choice != 'q') {
        displayGrid();    // Show the current generation
        updateGrid();     // Move to the next generation

        // Wait for user to press 'q' or any key to continue
        cout << "Press any key to see the next generation (or 'q' to quit): ";
        cin >> choice;  // Get input from user
    }

    return 0;
}

