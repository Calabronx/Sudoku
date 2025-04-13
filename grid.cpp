#include "grid.h"
#include <iostream>

Grid::Grid() {
    initGrid(); // initialize the 9x9 sudoku grid
}

void Grid::initGrid()
{
     //m_grid(9, std::vector<int>(9,9));

    // m_grid.push_back({0,0,0,0,0,0,0,0,0});
    // m_grid.push_back({0,0,0,0,0,0,0,0,0});
    // m_grid.push_back({0,0,0,0,0,0,0,0,0});
    // m_grid.push_back({0,0,0,0,0,0,0,0,0});
    // m_grid.push_back({0,0,0,0,0,0,0,0,0});
    // m_grid.push_back({0,0,0,0,0,0,0,0,0});
    // m_grid.push_back({0,0,0,0,0,0,0,0,0});
    // m_grid.push_back({0,0,0,0,0,0,0,0,0});
    // m_grid.push_back({0,0,0,0,0,0,0,0,0});

    m_grid = 
            {{0,0,0,0,0,0,0,0,0},
             {0,0,0,0,0,0,0,0,0},
             {0,0,0,0,0,0,0,0,0},
             {0,0,0,0,0,0,0,0,0},
             {0,0,0,0,0,0,0,0,0},
             {0,0,0,0,0,0,0,0,0},
             {0,0,0,0,0,0,0,0,0},
             {0,0,0,0,0,0,0,0,0},
             {0,0,0,0,0,0,0,0,0},
            };

    

    printGrid();
}

Grid::~Grid()
{
    
}

void Grid::printGrid()
{

    for (int row = 0; row < m_grid.size(); row++)
    {
        for (int col = 0; col< m_grid.size(); col++)
        {
            std::cout << m_grid[row][col] << ","; 
        }
        std::cout << std::endl;
    }

    std::cout << "9x9 grid initialized" << std::endl;
}