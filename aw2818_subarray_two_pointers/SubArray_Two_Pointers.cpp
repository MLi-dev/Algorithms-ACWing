#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5+10;
int a[N], b[N];

int main() {
    int n, m;
    cin>>n>>m;
    for(int i = 0; i<n; i++) {
        cin>>a[i];
    }
    for(int i = 0; i<m; i++) {
        cin >> b[i];
    }
    int i = 0;
    for(int j = 0; j<m && i<n; j++) {
        if(a[i] == b[j]) i++;
    }
    if(i==n) {
        puts("Yes");
    } else {
        puts("No");
    }

}