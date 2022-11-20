#include <iostream>
#include <cstring>
#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;
const int N = 155, M = N*N;
PII q[M];
int dist[N][N];
char g[N][N];
int n, m;

int bfs(int sx, int sy) {
    int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
    int dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
    q[0] = {sx, sy};
    memset(dist, -1, sizeof dist);
    dist[sx][sy] = 0;
    int hh = 0, tt = 0;
    while(hh<=tt) {
        auto t = q[hh++];
        for(int i = 0; i<8; i++) {
            int nx = t.x + dx[i];
            int ny = t.y + dy[i];
            if(nx < 0 || nx >= n || ny<0 || ny>= m) continue;
            if(dist[nx][ny] != -1) continue;
            if(g[nx][ny] == '*') continue;
            if(g[nx][ny] == 'H') {
                return dist[t.x][t.y]+1;
            }
            dist[nx][ny] = dist[t.x][t.y] + 1;
            q[++tt] = {nx, ny};
        }
    }
    return -1;
}

int main() {
    scanf("%d%d", &m, &n);
    PII start;
    for(int i = 0; i<n; i++) {
        scanf("%s", g[i]);
    }
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            if(g[i][j] == 'K') {
                start = {i, j};
            }
        }
    }
    int distance = bfs(start.x, start.y);
    printf("%d", distance);

}