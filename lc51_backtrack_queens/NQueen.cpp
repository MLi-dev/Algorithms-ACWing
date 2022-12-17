#include <vector>
#include <cstring>
#include <iostream>

using namespace std;
vector<vector<string>> result;
vector<string> path;
vector<bool> col, dg, udg;
int n;

void dfs(int y) {
    if (y == n) {
        result.push_back(path);
        return;
    }
    for (int x = 0; x < n; x++) {
        if (!col[x] && !dg[y - x + n] && !udg[y + x]) {
            col[x] = dg[y - x + n] = udg[y + x] = true;
            path[x][y] = 'Q';
            dfs(y + 1);
            col[x] = dg[y - x + n] = udg[y + x] = false;
            path[x][y] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int _n) {
    n = _n;
    col = vector<bool>(n, false);
    dg = udg = vector<bool>(2 * n, false);
    path = vector<string>(n, string(n, '.'));
    dfs(0);
    return result;
}

int main() {
    cin >> n;
    result = solveNQueens(n);
    for (auto e: result) {
        for (auto i: e) {
            for (auto j: i) {
                cout << j << " ";
            }
            puts("");
        }
        puts("---------------------");
    }
}