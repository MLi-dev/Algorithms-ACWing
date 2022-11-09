#include <iostream>
using namespace std;
const int N = 1e5+10;
int q[N], temp[N];

void mergeSort(int q[], int l, int r) {
    if(l>=r) {
        return;
    }
    int mid = (l+r)>>1;
    mergeSort(q, l, mid);
    mergeSort(q, mid+1, r);
    int i = l, j = mid+1, k = 0;
    while(i<= mid && j<= r) {
        if(q[i] < q[j]) temp[k++] = q[i++];
        else temp[k++] = q[j++];
    }
    while(i<=mid) {
        temp[k++] = q[i++];
    }
    while(j<=r) {
        temp[k++] = q[j++];
    }
    for(int i = l, j = 0; i<= r; i++, j++) {
        q[i] = temp[j];
    }
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i<=n; i++) {
        scanf("%d", &q[i]);
    }
    mergeSort(q, 1, n);
    for(int i = 1; i<=n; i++) {
        printf("%d ", q[i]);
    }
    return 0;
}