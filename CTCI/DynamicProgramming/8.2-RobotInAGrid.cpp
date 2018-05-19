#include<iostream>
#include<vector>
using namespace std;


const char allowed = '.';
const char notAllowed = '*';

//dp(i,j) -> number of ways of reaching grid[i][j]
//dp(i,j) = dp(i-1,j) + dp(i,j-1)
//if (i,j) is not allowed, dp(i,j) = 0.
// i and j are 0-indexed

int dp(vector<vector<char>>& grid, int r, int c, vector<vector<int>>& memo) {

	if (r < 0 || c < 0) {
		return 0;
	}

	if (grid[r][c] == notAllowed) {
		memo[r][c] = 0;
		return memo[r][c];
	}
	if (r == 0 && c == 0) {
		memo[r][c] = 1;
		return memo[r][c];
	}
	
	if (memo[r][c] != -1) {
		return memo[r][c];
	}

	return (memo[r][c] = dp(grid, r - 1, c, memo) + dp(grid, r, c - 1, memo));
	
	
}


int main() {
	
	vector<vector<char>> grid = { {'.','.','*'},
								{'.','*','.'},
								{'.','.','.'} };
	int rowSize = grid.size();
	int colSize = grid[0].size();
	vector<vector<int>> memo(rowSize,vector<int>(colSize, -1));
	cout << dp(grid, 2, 2, memo);


										
}
