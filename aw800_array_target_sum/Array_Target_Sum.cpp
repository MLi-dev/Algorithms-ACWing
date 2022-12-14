#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5+10;
int a[N], b[N];


int main() {
    int n, m, target;
    cin>>n>>m>>target;
    for(int i = 0; i<n; i++) {
        cin>>a[i];
    }
    for(int i = 0; i<m; i++) {
        cin>>b[i];
    }
    for(int i = 0, j=m-1; i<n; i++) {
        while(j>=0 && a[i]+b[j]>target) {
            j--;
        }
        if(j>=0 && a[i]+b[j] == target) {
            cout<<i<<" "<<j<<endl;
        }
    }
    return 0;
}
