#include <iostream>
#include <cstring>
#include <algorithm>
#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;
const int N = 55, M = N*N;
PII q[M];
bool st[N][N];
int g[N][N];
int n, m;

int bfs(int sx, int sy) {
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};
    q[0] = {sx, sy};
    st[sx][sy] = true;
    int hh = 0, tt = 0;
    int area = 0;
    while(hh<=tt) {
        auto t = q[hh++];
        area++;
        for(int i = 0; i<4; i++) {
            int nx = t.x + dx[i];
            int ny = t.y + dy[i];
            if(g[t.x][t.y] >> i & 1) continue;
            if(nx < 0 || nx>=n || ny<0 || ny>=m) continue;
            if(st[nx][ny]) continue;
            st[nx][ny] = true;
            q[++tt] = {nx, ny};
        }
    }
    return area;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            scanf("%d", &g[i][j]);
        }
    }
    int cnt = 0;
    int area = 0;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            if(!st[i][j]) {
                area = max(area, bfs(i, j));
                cnt++;
            }
        }
    }
    printf("%d\n", cnt);
    printf("%d\n", area);
}
