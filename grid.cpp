#include "grid.h"

#include <iostream>
#include <unordered_set>

Grid::Grid() {
    initGrid(); // initialize the 9x9 sudoku grid
}

void Grid::initGrid()
{
     //m_grid(9, std::vector<int>(9,9)); otra manera de inicializar la grid

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

std::vector<std::vector<int>> Grid::solveGrid(std::vector<std::vector<int>> grid, int start, int end)
{
    std::unordered_set<int> visited;

    std::vector<int> path;
    path.push_back(start);

    int currentPoint = start;
    visited.insert(currentPoint);

    while()

}