
#include <iostream>
#include <vector>

struct Grid {
    int N;
    std::vector<std::vector<bool>> grid;
    Grid(int s) : N{s}, grid(s, std::vector<bool>(s)) {}
};

// Returns the number of flips (including this flip) required to ensure that
// no flipped tile is white
int flipDownRight(Grid &g, int r, int c);
int flipUpRight(Grid &g, int r, int c);

int flipDownRight(Grid &g, int r, int c) {
    int flips = 1;
    g.grid[r][c] = !g.grid[r][c];
    for (int i = 1; i < g.N; ++i) {
        if (r-i >= 0 && c-i >= 0) g.grid[r-i][c-i] = !g.grid[r-i][c-i];
        if (r+i < g.N && c+i < g.N) g.grid[r+i][c+i] = !g.grid[r+i][c+i];
    }

    for (int i = 1; i < g.N; ++i) {
        if (r-i >= 0 && c-i >= 0 && !g.grid[r-i][c-i])
            flips += flipUpRight(g, r-i, c-i);
        if (r+i < g.N && c+i < g.N && !g.grid[r+i][c+i])
            flips += flipUpRight(g, r+i, c+i);
    }
    return flips;
}

int flipUpRight(Grid &g, int r, int c) {
    int flips = 1;
    g.grid[r][c] = !g.grid[r][c];
    for (int i = 1; i < g.N; ++i) {
        if (r-i >= 0 && c+i < g.N) g.grid[r-i][c+i] = !g.grid[r-i][c+i];
        if (r+i < g.N && c-i >= 0) g.grid[r+i][c-i] = !g.grid[r+i][c-i];
    }

    for (int i = 1; i < g.N; ++i) {
        if (r-i >= 0 && c+i < g.N && !g.grid[r-i][c+i])
            flips += flipDownRight(g, r-i, c+i);
        if (r+i < g.N && c-i >= 0 && !g.grid[r+i][c-i])
            flips += flipDownRight(g, r+i, c-i);
    }
    return flips;
}

int search(Grid &g) {
    for (int r = 0; r < g.N; ++r) {
        for (int c = 0; c < g.N; ++c) {
            if (!g.grid[r][c]) {
                Grid g1 = g;
                int drMin = flipDownRight(g1, r, c);
                drMin += search(g1);
                Grid g2 = g;
                int urMin = flipUpRight(g2, r, c);
                urMin += search(g2);
                return std::min(drMin, urMin);
            }
        }
    }
    return 0;
}

int main() {
    int T; std::cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N; std::cin >> N;
        Grid g(N);
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                char ch; std::cin >> ch;
                g.grid[r][c] = ch == '#';
            }
        }
        std::cout << "Case #" << t << ": " << search(g) << std::endl;
    }
    return 0;
}
