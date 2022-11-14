#include <iostream>
#include <cstring>
#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;
const int N = 1010, M = N*N;
PII q[M];
bool st[N][N];
char g[N][N];
int n, m;

void bfs(int sx, int sy) {
    q[0] = {sx, sy};
    st[sx][sy] = true;
    int hh = 0, tt = 0;
    while(hh<=tt) {
        auto t = q[hh++];
        for(int i = t.x-1; i<=t.x+1; i++) {
            for(int j = t.y-1; j<=t.y+1; j++) {
                if(i< 0 || i>=n || j<0 || j>=m) continue;
                if(st[i][j]) continue;
                if(t.x == i && t.y == j) continue;
                if(g[i][j] == '.') continue;
                q[++tt] = {i, j};
                st[i][j] = true;
            }
        }
    }
}


int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i<n; i++) {
        scanf("%s", g[i]);
    }
    for(int i = 0; i<n; i++) {
        printf("%s", g[i]);
    }
    int cnt = 0;
    for(int i = 0; i<n; i++) {
        for(int j = 0; i<m; j++) {
            if(!st[i][j] && g[i][j] == 'W') {
                bfs(i, j);
                cnt++;
            }
        }
    }
printf("%d", cnt);
}