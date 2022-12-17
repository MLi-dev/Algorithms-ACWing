#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5+10;

int lowBit(int x) {
    return x & -x;
}

int main() {
    int n;
    cin>>n;
    while(n--) {
        int x;
        cin>>x;
        int cnt = 0;
        while(x) {
            x -= lowBit(x);
            cnt++;
        }
        cout<<cnt<<" ";
    }
}