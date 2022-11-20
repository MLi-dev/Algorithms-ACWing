#include <iostream>
#include <cstring>
#include <algorithm>
#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;
const int N = 1010, M = N*N;
PII q[M];
int dist[N][N];
char g[N][N];
int n, m;

void bfs() {
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};
    memset(dist, -1, sizeof dist);
    int hh = 0, tt = -1;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            if(g[i][j] == '1') {
                q[++tt] = {i, j};
                dist[i][j] = 0;
            }
        }
    }
    while(hh<=tt) {
        auto t = q[hh++];
       // printf("%d%d ", t.x, t.y);
        for(int i = 0; i<4; i++) {
            int nx = t.x+dx[i];
            int ny = t.y+dy[i];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(dist[nx][ny] != -1) continue;
            if(g[nx][ny] == '1') continue;
            q[++tt] = {nx, ny};
            dist[nx][ny] = dist[t.x][t.y] + 1;
        }
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                printf("%d", dist[i][j]);
            }
            puts("");
        }
    }

}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i<n; i++) {
       scanf("%s", g[i]);
    }
   bfs();
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            printf("%d", dist[i][j]);
        }
        puts("");
    }
}