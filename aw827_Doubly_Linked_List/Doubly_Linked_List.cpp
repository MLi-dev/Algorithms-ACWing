#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e5+10;
int l[N], r[N], e[N], idx;

void init() {
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}

void add(int k, int b) {
    e[idx] = b;
    l[idx] = k;
    r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx;
    idx++;
}

void remove(int k) {
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}
int main() {
    int n;
    cin>>n;
    init();
    while(n--) {
        int k, b;
        string s;
        cin>>s;
        if(s == "R") { //Finds left add at right of it. Goal is to add a bead before left of dummy beads' "1".
            cin>>b;
            add(l[1], b);
        } else if(s == "L") {
            cin>>b;
            add(0, b);
        } else if(s=="IL") {
            cin>>k>>b;
            add(l[k+1], b);
        } else if(s=="IR") {
            cin>>k>>b;
            add(k+1, b);
        }
        else if(s == "D") {
            cin>>k;
            remove(k+1);
        }
    }
    for(int i = r[0]; i!= 1; i = r[i]) {
        cout<<e[i]<<" ";
    }
    puts("");
}