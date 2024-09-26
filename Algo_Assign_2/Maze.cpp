#include <iostream>
#include <vector>

using namespace std;

struct Position {
    int x;
    int y;
};

int rows, cols;
vector<vector<char>> maze;
vector<vector<bool>> visited;

// Function to check if a cell is valid for movement
bool isValid(int x, int y) {
    return x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] != '#' && !visited[x][y];
}

// Recursive function to find the path from Rezia's position to exit
bool findPath(int x, int y) {
    // Check if the exit is reached
    if (maze[x][y] == 'D') {
        return true;
    }

    visited[x][y] = true; // Mark the current position as visited

    // Try moving in the specified order: right, left, up, down
    if (isValid(x, y + 1) && findPath(x, y + 1)) {
        maze[x][y] = 'X'; // Mark path when moving right
        return true;
    }
    if (isValid(x, y - 1) && findPath(x, y - 1)) {
        maze[x][y] = 'X'; // Mark path when moving left
        return true;
    }
    if (isValid(x - 1, y) && findPath(x - 1, y)) {
        maze[x][y] = 'X'; // Mark path when moving up
        return true;
    }
    if (isValid(x + 1, y) && findPath(x + 1, y)) {
        maze[x][y] = 'X'; // Mark path when moving down
        return true;
    }

    // If no valid path found, unmark the current cell
    visited[x][y] = false;
    return false; // No valid path found from this position
}

int main() {
    cin >> rows >> cols;

    maze.resize(rows, vector<char>(cols));
    visited.resize(rows, vector<bool>(cols, false));

    int startX = -1, startY = -1; // Initialize starting position

    // Input the maze
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 'R') {
                startX = i;
                startY = j; // Record Rezia's starting position
            }
        }
    }

    // Ensure start position is valid
    if (startX == -1 || startY == -1) {
        cout << "No starting position found." << endl;
        return 0; // Exit if no starting position found
    }

    // Find path from Rezia's starting position
    if (findPath(startX, startY)) {
        // If a path is found, print the maze
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // If the cell is part of the path and not 'D' or 'R', we print 'X'
                if (maze[i][j] == 'X') {
                    cout << 'X';
                } else {
                    cout << maze[i][j]; // Print other cells as is
                }
            }
            cout << endl;
        }
    } else {
        // If no path is found, print the original maze
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << maze[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}