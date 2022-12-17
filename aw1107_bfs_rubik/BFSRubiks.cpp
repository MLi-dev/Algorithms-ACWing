#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <unordered_map>
#define x first
#define y second
using namespace std;
typedef pair<char, string> PII;
queue<string> q;
unordered_map<string, int> dist;
unordered_map<string, PII> pre;
int g[2][4];

void setGrid(string state) {
    for(int i = 0; i<4; i++) {
        g[0][i] = state[i];
    }
    for(int i = 0, j = 7; i<4; i++, j--) {
        g[1][i] = state[j];
    }
}

string getFromGrid() {
    string resp = "";
    for(int i = 0; i<4; i++) {
        resp += g[0][i];
    }
    for(int j = 3; j>=0; j--) {
        resp+=g[1][j];
    }
    return resp;
}

string move0(string state) {
    setGrid(state);
    for(int i = 0; i<4; i++) {
        swap(g[0][i], g[1][i]);
    }
    return getFromGrid();
}

string move1(string state) {
    setGrid(state);
    int temp0 = g[0][3];
    int temp1 = g[1][3];
    for(int i = 3; i>=1; i--) {
        g[0][i] = g[0][i-1];
        g[1][i] = g[1][i-1];
    }
    g[0][0] = temp0;
    g[1][0] = temp1;
    return getFromGrid();
}

string move2(string state) {
    setGrid(state);
    int temp = g[0][2];
    g[0][2] = g[0][1];
    g[0][1] = g[1][1];
    g[1][1] = g[1][2];
    g[1][2] = temp;
    return getFromGrid();
}

int bfs(string start, string end) {
    if(start == end) {
        return 0;
    }
    q.push(start);
    dist[start] = 0;
    while(!q.empty()) {
        string t = q.front();
        q.pop();
        string m[3];
        m[0] = move0(t);
        m[1] = move1(t);
        m[2] = move2(t);
        for(int i = 0; i<3; i++) {
            if(dist.count(m[i]) == 0) {
                q.push(m[i]);
                dist[m[i]] = dist[t]+1;
                pre[m[i]] = {'A'+i, t};
                if(m[i] == end) {
                    return dist[m[i]];
                }
            }
        }
    }
    return -1;
}


int main() {
    string end = "";
    string start = "12345678";
    for(int i = 0; i<8; i++) {
        int c;
        cin>>c;
        end+=c+'0';
    }
    int steps = bfs(start, end);
    cout<<steps<<endl;
    string res = "";
    while(start!=end) {
        res+=pre[end].x;
        end = pre[end].y;
    }
    reverse(res.begin(), res.end());
    if(steps>0) {
        cout<<res<<endl;
    }

}