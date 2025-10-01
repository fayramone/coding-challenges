#include <iostream>
#include <vector>

struct Cell {
    int x, y;
    bool isMine = false;
    int minesNum = 0;
};

struct Field {
    std::vector<std::vector<Cell>> cells;
    int m, n, k;
};

int main() {
    Field f;
    std::cin >> f.m >> f.n >> f.k;

    std::size_t rows = static_cast<std::size_t>(f.m);
    std::size_t cols = static_cast<std::size_t>(f.n);

    f.cells.resize(rows);
    for (std::size_t i = 0; i < rows; ++i) {
        f.cells[i].resize(cols);
        for (std::size_t j = 0; j < cols; ++j) {
            f.cells[i][j] = Cell{static_cast<int>(i + 1), static_cast<int>(j + 1)};
        }
    }

    for (int mine = 0; mine < f.k; ++mine) {
        int x, y;
        std::cin >> x >> y;
        std::size_t idx_x = static_cast<std::size_t>(x - 1);
        std::size_t idx_y = static_cast<std::size_t>(y - 1);
        f.cells[idx_x][idx_y].isMine = true;
    }

    for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < cols; ++j) {
            if (!f.cells[i][j].isMine) {
                if (i > 0 && j > 0 && f.cells[i - 1][j - 1].isMine) f.cells[i][j].minesNum++;
                if (i > 0 && f.cells[i - 1][j].isMine) f.cells[i][j].minesNum++;
                if (i > 0 && j < cols - 1 && f.cells[i - 1][j + 1].isMine) f.cells[i][j].minesNum++;
                if (j > 0 && f.cells[i][j - 1].isMine) f.cells[i][j].minesNum++;
                if (j < cols - 1 && f.cells[i][j + 1].isMine) f.cells[i][j].minesNum++;
                if (i < rows - 1 && j > 0 && f.cells[i + 1][j - 1].isMine) f.cells[i][j].minesNum++;
                if (i < rows - 1 && f.cells[i + 1][j].isMine) f.cells[i][j].minesNum++;
                if (i < rows - 1 && j < cols - 1 && f.cells[i + 1][j + 1].isMine) f.cells[i][j].minesNum++;
            }
        }
    }

    for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < cols; ++j) {
            if (f.cells[i][j].isMine)
                std::cout << "* ";
            else
                std::cout << f.cells[i][j].minesNum << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
