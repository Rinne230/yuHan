#include <iostream>
#include <vector>

using namespace std;

bool checkWin(const vector<vector<char>>& grid, char symbol) {
    for (int i = 0; i < 3; i++) {
        if (grid[i][0] == symbol && grid[i][1] == symbol && grid[i][2] == symbol) {
            return true;
        }
    }
    for (int j = 0; j < 3; j++) {
        if (grid[0][j] == symbol && grid[1][j] == symbol && grid[2][j] == symbol) {
            return true;
        }
    }
    if (grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol) {
        return true;
    }
    if (grid[0][2] == symbol && grid[1][1] == symbol && grid[2][0] == symbol) {
        return true;
    }

    return false;
}

string findWinner(const vector<vector<char>>& grid) {
    if (checkWin(grid, 'X')) {
        return "X";
    } else if (checkWin(grid, 'O')) {
        return "O";
    } else if (checkWin(grid, '+')) {
        return "+";
    } else {
        return "DRAW";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<vector<char>> grid(3, vector<char>(3));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> grid[i][j];
            }
        }

        string result = findWinner(grid);
        cout << result << endl;
    }

    return 0;
}
