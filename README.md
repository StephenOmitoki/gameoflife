# gameoflife

Overview:
This program simulates the Game of Life, a grid-based game where cells live or die based on the number of live neighbors they have. The game follows simple rules to determine whether each cell in the grid lives, dies, or becomes alive in the next generation.

How to Run:
Input the Initial Live Cells:

After running the program, you'll be prompted to enter the coordinates of live cells.
Enter the x and y coordinates (e.g., 2 3) for each live cell.
To stop entering coordinates, input -1 -1.


After entering the initial configuration, the grid will display the first generation of cells.
The program will prompt you to press any key to view the next generation or press q to quit.


Game Rules:

Live Cell:
Lives if it has 2 or 3 live neighbors.
Dies if it has fewer than 2 (underpopulation) or more than 3 (overcrowding) neighbors.

Dead Cell:
Becomes alive if it has exactly 3 live neighbors.

Grid Size:
The grid is 10x10 by default. Cells outside this range are ignored.

Requirements:
C++ compiler

Quit the Program:
To quit at any time, press q.

Files:
main.cpp: Contains the main logic of the program, user interaction, and game loop.
gameoflife.cpp: Handles the game logic, grid updates, and neighbor counting.
