#include "sudoku.h"

#include <iostream>

Sudoku::Sudoku()
{
	init();
}

Sudoku::~Sudoku()
{
	delete m_game_grid;
}

int Sudoku::init()
{
	int dificulty = 0;
	std::cout << "game init" << std::endl;
	std::cout << std::endl;
	std::cout << "Choose game dificulty" << std::endl;
	std::cin >> dificulty;
	std::cout << std::endl;
	std::cout << "EASY: 1 " << std::endl;
	std::cout << "MEDIUM: 2 " << std::endl;
	std::cout << "HARD: 3 " << std::endl;
	std::cout << std::endl;

	m_game_grid = new Grid(dificulty);

	return 0;
}

void Sudoku::run()
{
	bool exit = false;
	int row;
	int col;
	int num;
	std::cout << "Play status" << std::endl;
	while (!exit) //es infinito por ahora
	{
		std::cout << "Enter the row" << std::endl;

		std::cin >> row;
		std::cout << "Enter the col" << std::endl;
		std::cin >> col;

		bool empty = false;
		if (m_game_grid->isCellEmpty(row, col))
		{
			std::cout << "cell choose is not empty" << std::endl;
			empty = true;
		}

		std::cout << "Enter the choose number" << std::endl;
		std::cin >> num;

		if (num <= 9)
		{

			m_game_grid->printGrid();

			if (empty)
			{
				if (!m_game_grid->isSafe(row, col, num))
				{
					std::cout << "num " << num << "is not safe" << std::endl;
				}
				else {
					std::cout << "num " << num << "is safe!" << std::endl;
					m_game_grid->addNum(row, col, num);
					m_game_grid->printGrid();
				}
			}
		}
		else {
			std::cout << "Number must be from range 1-9" << std::endl;
		}

	}
}

void Sudoku::update()
{

}

void Sudoku::render()
{

}