#include <iostream>
#include <vector>
#include <algorithm>

#define x first
#define y second
using namespace std;
const int N = 1e5 + 10;
int head, e[N], ne[N], idx;

void init() {
    head = -1;
    idx = 0;
}

void add(int k, int b) {
    e[idx] = b;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}

void add_at_head(int b) {
    e[idx] = b;
    ne[idx] = head;
    head = idx;
    idx++;
}

void remove(int k) {
    ne[k] = ne[ne[k]];
}

int main() {
    int nums;
    cin>>nums;
    init();
    while(nums--) {
        char c;
        int b, k;
        cin>>c;
        switch(c) {
            case 'H':
                cin>>b;
                add_at_head(b);
            break;
            case 'I':
                cin>>k>>b;
                add(k-1, b);
            break;
            case 'D':
                cin>>k;
                if(k == 0) {
                    head = ne[head];
                }
                else remove(k-1);
            break;
            default:
                break;
        }
    }
    for(int i = head; i != -1; i = ne[i]) {
        cout<<e[i]<<" ";
    }
}
