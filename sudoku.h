#ifndef SUDOKU_H
#define SUDOKU_H

#include "grid.h"
#include "window.h"
#include "renderer.h"

class Sudoku
{
	public:
					Sudoku();
					~Sudoku();
	public:
		void		run();
	private:
		int			init();
		void		update();
		void		render();

	private:
		Grid *		m_game_grid;
		Window*		m_game_window;
		Renderer*	m_game_renderer;
};

#endif