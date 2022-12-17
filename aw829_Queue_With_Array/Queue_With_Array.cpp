#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e5+10;
int hh = 0, tt = 0;
int q[N];

int main() {
    int n;
    cin>>n;
    while(n--) {
        int val;
        string s;
        cin>>s;
        if(s=="push") {
            cin>>val;
            q[tt++] = val;
        } else if(s=="pop") {
            hh++;
        } else if(s == "empty") {
            if(hh==tt) puts("YES");
            else puts("NO");
        }
        else if(s=="query") {
            cout<<q[hh]<<endl;
        }
    }
}