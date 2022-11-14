#include <iostream>
#include <cstring>
#include <algorithm>
#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;
const int N = 1010, M = N*N;
PII q[M];
bool st[N][N];
int g[N][N];
int n;

void bfs(int sx, int sy, bool &has_lower, bool &has_higher) {
    q[0] = {sx, sy};
    st[sx][sy] = true;
    int hh = 0, tt = 0;
    while(hh<=tt) {
        auto t = q[hh++];
        for(int i = t.x-1; i<= t.x+1; i++) {
            for(int j = t.y-1; j<= t.y+1; j++) {
                if(i<0 || i>= n || j<0 || j>=n) continue;
                if(i == t.x && j == t.y) continue;
                if(g[t.x][t.y] != g[i][j]) {
                    if(g[t.x][t.y] >g[i][j]) has_lower = true;
                    else has_higher = true;
                }
                else {
                    if(st[i][j])  continue;
                    q[++tt] = {i, j};
                    st[i][j] = true;
                }
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            scanf("%d", &g[i][j]);
        }
    }
    int peaks = 0;
    int valleys = 0;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            bool has_lower = false;
            bool has_higher = false;
            if(!st[i][j]) {
                bfs(i, j, has_lower, has_higher);
                if(!has_lower) valleys++;
                if(!has_higher) peaks++;
            }
        }
    }
    printf("%d %d", peaks, valleys);
}