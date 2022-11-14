#include <iostream>
using namespace std;
typedef long long LL;
const int N = 1e5+10;
int q[N], temp[N];

LL mergeSort(int q[], int l, int r) {
    if(l>=r) {
        return 0;
    }
    int mid = (l+r)>>1;
    LL resp = mergeSort(q, l, mid) + mergeSort(q, mid+1, r);
    int i = l, j = mid+1, k=0;
    while(i<=mid && j<=r) {
        if(q[i] <= q[j]) temp[k++] = q[i++];
        else {
            temp[k++] = q[j++];
            resp += mid-i+1;
        }
    }
    while(i<=mid) {
        temp[k++] = q[i++];
    }
    while(j <= r) {
        temp[k++] = q[j++];
    }
    for(int i = l, j = 0; i<=r; i++, j++) {
        q[i] = temp[j];
    }
    return resp;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i<=n; i++) {
        scanf("%d", &q[i]);
    }
    LL resp = mergeSort(q, 1, n);
    printf("%d ", resp);
}