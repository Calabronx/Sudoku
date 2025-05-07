#ifndef GRID_H
#define GRID_H
/**
 * Clase grid para manejar la grilla de sudoku
 * width
 * 
 **/ 
#include <SDL2/SDL.h>

#include <vector>
#include <unordered_set>

#include "consts.h"

enum Dificulty
{
	EASY = 1,
	MEDIUM = 2,
	HARD = 3,
};

class Grid
{
	public:
		Grid(int grid_dificulty);
		~Grid();

	private:
		void initGrid();
		void generateGrid(std::vector<std::vector<int>>& grid);
		void fillBox(std::vector<std::vector<int>>& grid, std::unordered_set<int>& check_nums, int row, int col);
		bool solveSudokuRec(std::vector<std::vector<int>>& grid, int row, int col);
		void solveSudoku(std::vector<std::vector<int>>& grid);
		//definir metodo que elimine valores random de celdas (por cuadrado y que no los vacie)
		void removeKCells(std::vector<std::vector<int>>& grid, int k);
		void printGrid(std::vector<std::vector<int>> grid);

	public:
		bool isSafe(int row, int col, int num);
		bool isCellEmpty(int row, int col);
		void addNum(int row, int col, int num);
		void printGrid();
		void drawGrid(SDL_Window* window, SDL_Renderer* renderer);
	private:
		std::vector<std::vector<int>> m_grid; // 2d grid
		int m_grid_dificulty;

};

#endif
