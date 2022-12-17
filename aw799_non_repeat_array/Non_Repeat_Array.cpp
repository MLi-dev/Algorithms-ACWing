#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5+10;
int a[N], cnt[N];

int main() {
    int n;
    int resp = 0;
    cin>>n;
    for(int i = 0; i<n; i++) {
        cin>>a[i];
    }
    for(int i = 0, j = 0; i<n; i++) {
        cnt[a[i]]++;
        while(j<=i && cnt[a[i]]>1) {
            cnt[a[j]]--;
            j++;
        }
        resp = max(resp, i-j+1);
    }
    cout<<resp;
}