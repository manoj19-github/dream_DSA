
#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;


bool isValid(int x, int y, vector<vector<int>>& maze, vector<vector<int>>& visited, int n) {
	if ((x < n && x >= 0) && (y < n && y >= 0) && visited[x][y] == 0 && maze[x][y] == 1) return true;
	return false;
}
void solve(vector<vector<int>>& maze, int n, vector<string>& ans, int x, int y, vector<vector<int>>visited, string path) {
	// base case 
	if (x == n - 1 && y == n - 1)  return ans.push_back(path);
	visited[x][y] = 1; // marked current position within maze  to avoid infinite loop
	// left direction 
	int newX = x;
	int newY = y - 1;
	if (isValid(newX, newY, maze, visited, n)) {
		path.push_back('L');
		solve(maze, n, ans, newX, newY, visited, path);
		path.pop_back();  // backtracking

	}

	// right direction 

	newX = x;
	newY = y + 1;
	if (isValid(newX, newY, maze, visited, n)) {
		path.push_back('R');
		solve(maze, n, ans, newX, newY, visited, path);
		path.pop_back();  // backtracking

	}
	// up direction 
	newX = x - 1;
	newY = y;
	if (isValid(newX, newY, maze, visited, n)) {
		path.push_back('U');
		solve(maze, n, ans, newX, newY, visited, path);
		path.pop_back();  // backtracking

	}

	// bottom direction 
	newX = x + 1;
	newY = y;
	if (isValid(newX, newY, maze, visited, n)) {
		path.push_back('D');
		solve(maze, n, ans, newX, newY, visited, path);
		path.pop_back();  // backtracking

	}
	visited[x][y] = 0; // to revisited again to find another possible path





}

void findPath(vector<vector<int>>maze, vector<string>& ans, int n) {
	if (maze[0][0] == 0) return;
	int srcx = 0;
	int srcy = 0;
	vector<vector<int>>visited = maze;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
		}
	}
	string path = "";
	solve(maze, n, ans, srcx, srcy, visited, path);
	sort(ans.begin(), ans.end());


}

void main() {
	vector<vector<int>>maze = { {1,0,0,0,},{1,1,0,1},{1,1,0,0},{0,1,1,1} };

	vector<string>ans;
	findPath(maze, ans, 4);
	cout << endl;
	cout << "Answer is : " << endl;
	for (string items : ans) {
		cout << items << " ";
	}



}

