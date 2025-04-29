#ifndef SUDOKU_H
#define SUDOKU_H

#include "grid.h"

class Sudoku
{
	public:
		Sudoku();
		~Sudoku();
	public:
		void run();
	private:
		int	 init();
		void update();
		void render();

	private:
		Grid *m_game_grid;
};

#endif