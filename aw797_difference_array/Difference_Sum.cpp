#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5+10;
int n, m;
int a[N], b[N];

void insert(int l, int r, int c) {
    b[l] += c;
    b[r+1]-=c;
}

int main() {
    cin>>n>>m;
    for(int i = 1; i<=n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        insert(i, i, a[i]);

    }
    for (int i = 1; i <= n; i++) {
        cout<<b[i]<<" ";

    }
    while(m--) {
        int l, r, c;
        cin>>l>>r>>c;
    }

}