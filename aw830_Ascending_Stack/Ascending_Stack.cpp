#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e5+10;
int stk[N];
int tt = -1;

int main() {
    int n;
    cin>>n;
    while(n--) {
        int val;
        cin>>val;
        while(stk[tt] > val) {
            --tt;
        }
        if(tt == -1) {
            cout<<"-1"<<" ";
        } else {
            cout<<stk[tt]<<" ";
        }
        stk[++tt] = val;
    }
}