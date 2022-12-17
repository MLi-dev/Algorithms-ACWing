#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e5+10;
int top = -1;
int stk[N];

int main() {
    int n;
    cin>>n;
    while(n--) {
        string op;
        int x;
        cin>>op;
        if(op == "push") {
            cin>>x;
            stk[++top] = x;
        } else if(op == "pop") {
            --top;
        } else if(op == "query") {
            cout<<stk[top]<<endl;
        } else if(op == "empty") {
            if(top == -1) {
                puts("YES");
            } else {
                puts("NO");
            }
        }
    }
}