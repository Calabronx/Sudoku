#include "grid.h"

#include <iostream>
#include <unordered_set>
#include <time.h>

Grid::Grid(int grid_dificulty)
	: m_grid_dificulty(grid_dificulty)
{
	initGrid(); // initialize the 9x9 sudoku grid
}

void Grid::initGrid()
{
	m_grid =
	{ {0,0,0,0,0,0,0,0,0},
	 {0,0,0,0,0,0,0,0,0},
	 {0,0,0,0,0,0,0,0,0},
	 {0,0,0,0,0,0,0,0,0},
	 {0,0,0,0,0,0,0,0,0},
	 {0,0,0,0,0,0,0,0,0},
	 {0,0,0,0,0,0,0,0,0},
	 {0,0,0,0,0,0,0,0,0},
	 {0,0,0,0,0,0,0,0,0},
	};

	srand(time(NULL));

	generateGrid(m_grid);

	printGrid(m_grid);
	solveSudoku(m_grid);

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "solved grid: " << std::endl;
	printGrid(m_grid);

	int dificulty = 2;
	int k = 0;

	switch (m_grid_dificulty)
	{
		case EASY:
			k = 32;
			break;
		case MEDIUM:
			k = 45;
			break;
		case HARD:
			k = 64;
			break;
	}

	removeKCells(m_grid, k);

	printGrid(m_grid);

	std::cout << std::endl;
	int zero_counter = 0;
	for (int row = 0; row < m_grid.size(); row++)
	{
		for (int col = 0; col < m_grid.size(); col++)
		{
			if (m_grid[row][col] == 0)
			{
				zero_counter++;
			}
		}
		std::cout << std::endl;
	}
	std::cout <<"0s: " << zero_counter << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "sudoku puzzle ready" << std::endl;
}


Grid::~Grid()
{

}

void Grid::printGrid()
{
	std::cout << std::endl;
	std::cout << " ";
	std::cout << "  ";
	for (int i = 0; i < 9; i++)
	{
		std::cout << "c" << i << " ";
	}
	std::cout << std::endl;
	for (int row = 0; row < m_grid.size(); row++)
	{
		std::cout << "r" << row << " ";
		for (int col = 0; col < m_grid.size(); col++)
		{
			std::cout << m_grid[row][col] << ", ";
		}
		std::cout << std::endl;
	}

	std::cout << "9x9 grid initialized" << std::endl;
}

void Grid::printGrid(std::vector<std::vector<int>> grid)
{
	std::cout << std::endl;
	std::cout << " ";
	std::cout << "  ";
	for (int i = 0; i < 9; i++)
	{
		std::cout << "c" << i << " ";
	}
	std::cout << std::endl;
	for (int row = 0; row < grid.size(); row++)
	{
		std::cout << "r" << row << " ";
	
		for (int col = 0; col < grid.size(); col++)
		{
			std::cout << grid[row][col] << ", ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

}

void Grid::fillBox(std::vector<std::vector<int>>& grid, std::unordered_set<int>& check_nums, int row, int col)
{
	bool safe = false;
	bool end = false;

	while (!end)
	{
		int rand_num = rand() % 9 + 1;
		if (check_nums.count(rand_num) == 0)
		{
			safe = isSafe(row, col, rand_num);
			if (safe)
			{
				grid[row][col] = rand_num;
				check_nums.insert(rand_num);
				end = true;
			}
		}
	}
}

void Grid::generateGrid(std::vector<std::vector<int>>& grid)
{
	printGrid(grid);
	std::unordered_set<int> check_nums;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			fillBox(grid, check_nums, i, j);
			printGrid(grid);
		}
	}
	check_nums.clear();
	for (int i = 3; i < 6; i++)
	{
		for (int j = 3; j < 6; j++)
		{
			fillBox(grid, check_nums, i, j);
			printGrid(grid);
		}
	}

	check_nums.clear();
	for (int i = 6; i < 9; i++)
	{
		for (int j = 6; j < 9; j++)
		{
			fillBox(grid, check_nums, i, j);
			printGrid(grid);
		}
	}
}

bool Grid::isSafe(const int row, const int col, int num)
{
	if (m_grid[row][col] == 0)
	{
		for (int r = 0; r <= 8; r++)
		{
			if (m_grid[r][col] == num) {
				return false;
			}
		}

		for (int c = 0; c <= 8; c++)
		{
			if (m_grid[row][c] == num) {
				return false;
			}

		}

		int startRow = row - (row % 3);
		int startCol = col - (col % 3);

		for (int r = 0; r < 3; r++)
		{
			for (int c = 0; c < 3; c++)
			{
				if (m_grid[r + startRow][c + startCol] == num)
				{
					return false;
				}
			}
		}
	}

	return true;
}

bool Grid::isCellEmpty(int row, int col)
{
	return m_grid[row][col] == 0;
}

void Grid::addNum(int row, int col, int num)
{
	m_grid[row][col] = num;
}

void Grid::removeKCells(std::vector<std::vector<int>>& grid, int k)
{
	while (k > 0)
	{
		int cellId = rand() % 81;

		int i = cellId / 9; // get row index

		int j = cellId % 9; // get col index

		if (grid[i][j] != 0)
		{
			grid[i][j] = 0;
			printGrid(grid);
			k--;
		}
	}
}

void Grid::solveSudoku(std::vector<std::vector<int>>& grid)
{
	solveSudokuRec(grid, 0, 0);
}

bool Grid::solveSudokuRec(std::vector<std::vector<int>>& grid, int row, int col)
{
	int n = grid.size();

	if (row == n - 1 && col == n)
		return true;

	if (col == n)
	{
		row++;
		col = 0;
	}

	if (grid[row][col] != 0)
		return solveSudokuRec(grid, row, col + 1);

	for (int num = 1; num <= n; num++)
	{
		if (isSafe(row, col, num))
		{
			grid[row][col] = num;
			if (solveSudokuRec(grid, row, col + 1))
			{
				return true;
			}
			grid[row][col] = 0;
		}
	}

	return false;
}