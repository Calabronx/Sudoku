#ifndef GRID_H
#define GRID_H
/**
 * Clase grid para manejar la grilla de sudoku
 * width
 * 
 **/ 
#include <vector>


class Grid
{
	public:
		Grid();
		~Grid();

	private:
		void initGrid();
		// std::vector<vector<int>> solveGrid(std::vector<vector<int>> grid, );		
	public:
		void printGrid();
	private:
		std::vector<std::vector<int>> m_grid; // 2d grid

};

#endif
