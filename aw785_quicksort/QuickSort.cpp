#include <iostream>
using namespace std;
const int N = 1e5+10;
int q[N];

void quickSort(int q[], int l, int r) {
    if(l>=r) {
        return;
    }
    int pivot = q[(l+r)>>1];
    int i = l-1, j = r+1;
    while(i<j) {
        do i++; while(q[i] < pivot);
        do j--; while(q[j] > pivot);
        if(i<j) swap(q[i], q[j]);
    }
    quickSort(q, l, j);
    quickSort(q, j+1, r);
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i<=n; i++) {
        scanf("%d", &q[i]);
    }
    quickSort(q, 1, n);
    for(int i = 1; i<=n; i++) {
        printf("%d ", q[i]);
    }
    return 0;
}