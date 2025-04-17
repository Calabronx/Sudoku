#include <iostream>
#include <vector>

#include "sudoku.h"

int main()
{

	// vector<vector<int>> grid(9, vector<int>(9,9));
	// vector<vector<int>> grid_empty;


	// for (int col = 0; col < 9; col++)
	// {
	// 	for (int row = 0; row < 9; row++)
	// 	{
	// 		//grid_empty[row + col * 9].push_back(2);
	// 	}
	// }

	// cout << grid.size() << endl;


	// // grid[0][1] = 7;
	// // grid[0][2] = 5;
	// // grid[0][3] = 1;
	// // grid[0][4] = 2;

	// cout << grid.size() << endl;
	// for (auto i : grid)
	// {
	// 	cout << endl;
	// 	for (auto j : i)
	// 	{
	// 		cout << j << ",";
	// 	}

	// }

	// //for (int col = 0; col < 9; col++)
	// //{
	// //	for (int row = 0; row < 9; row++)
	// //	{
	// //		cout << grid[col][row];
	// //		cout << ",";
	// //	}
	// //}
	// /*for (int i = 0; i < grid->size(); i++) {
	// 	cout << grid[0][i];
	// 		cout << ",";
	// }*/
	// //for (auto i : grid)
	// //{
	// //	cout << endl;
	// //	for (auto j : i)
	// //	{
	// //		cout << j << ",";
	// //	}

	// //}
	

	// vector<vector<int>> grid;
	// vector<vector<int>> grid_init(9, vector<int>(9,2));

	// grid.push_back({0,0,0,0,0,0,0,0});
	// grid.push_back({0,0,0,0,0,0,0,0});
	// grid.push_back({0,0,0,0,0,0,0,0});
	// grid.push_back({0,0,0,0,0,0,0,0});
	// grid.push_back({0,0,0,0,0,0,0,0});
	// grid.push_back({0,0,0,0,0,0,0,0});
	// grid.push_back({0,0,0,0,0,0,0,0});
	// grid.push_back({0,0,0,0,0,0,0,0});
	// grid.push_back({0,0,0,0,0,0,0,0});

	// for (int i = 0; i < grid.size(); i++) 
	// {
	// 	for (int j = 0; j < grid[i].size(); j++)
	// 	{
	// 		cout <<grid[i][j]<< ",";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;
	// cout << "init on line" << endl;

	// for (auto i : grid_init)
	// {
	// 	cout << endl;
	// 	for (auto j : i)
	// 	{
	// 		cout << j << ",";
	// 	}
	// }

	Sudoku *sudoku = new Sudoku();
	sudoku->run();

	return 0;
}