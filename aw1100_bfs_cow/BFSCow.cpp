#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5+10;
int dist[N];
int q[N];
int farmPos, cowPos;

int bfs() {
    q[0] = farmPos;
    int hh = 0, tt = 0;
    memset(dist, -1, sizeof dist);
    dist[farmPos] = 0;
    while(hh<=tt) {
        int t = q[hh++];
        if(t==cowPos) {
            return dist[t];
        }
        if(t-1>=0 && dist[t-1] == -1) {
            dist[t-1] = dist[t]+1;
            q[++tt] = t-1;
        }
        if(t+1 < N && dist[t+1] == -1) {
            dist[t+1] = dist[t]+1;
            q[++tt] = t+1;
        }
            if(2*t<N && dist[2*t] == -1) {
            dist[2 * t] = dist[t] + 1;
            q[++tt] = 2 * t;
        }
    }
    return -1;
}

int main() {
    scanf("%d%d", &farmPos, &cowPos);
    int minutes = bfs();
    printf("%d", minutes);
}