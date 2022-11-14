#include <iostream>
using namespace std;
const int N = 1e5+10;
int q[N];

int ls(int q[], int l, int r, int val) {
    while(l<r) {
        int mid = (l+r)>>1;
        if(q[mid] >= val) {
            r = mid;
        } else {
            l = mid+1;
        }
    }
    return l;
}
int rs(int q[], int l, int r, int val) {
    while(l<r) {
        int mid = (l+r+1)>>1;
        if(q[mid] <= val) {
            l = mid;
        } else {
            r = mid-1;
        }
    }
    return r;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i<n; i++) {
        scanf("%d", &q[i]);
    }
    while(m--) {
        int k;
        scanf("%d", &k);
        int start = ls(q, 0, n-1, k);
        int end = rs(q, 0, n-1, k);
        if(q[start] != k) {
            printf("%d %d\n", -1, -1);
        } else {
            printf("%d %d\n", start, end);
        }
    }
    return 0;
}