#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5+10;

int main() {
    int n;
    cin>>n;
    while(n--) {
        int x;
        cin>>x;
        int cnt = 0;
        while(x) {
            cnt += x & 1;
            x = x>>1;
        }
        cout<<cnt<<" ";
    }
}