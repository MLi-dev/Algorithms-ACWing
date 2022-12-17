#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;
const int N = 3e5+10;
int n, m;
int a[N];
int s[N];
vector<int> alls;
vector<PII> add;
vector<PII> query;

int find(int target) {
    int l = 0, r= alls.size()-1;
    while(l<r) {
        int mid = (l+r)>>1;
        if(alls[mid] >= target) {
            r = mid;
        } else {
            l = mid+1;
        }
    }
    return l;
}

int main() {
   scanf("%d%d", &n, &m);
   for(int i = 0; i<n; i++) {
       int x, val;
       scanf("%d%d", &x, &val);
       add.push_back({x, val});
       alls.push_back(x);
   }
   for(int i = 0; i<m; i++) {
       int l, r;
       scanf("%d%d", &l, &r);
       query.push_back({l, r});
       alls.push_back(l);
       alls.push_back(r);
   }
   sort(alls.begin(), alls.end());
   alls.erase(unique(alls.begin(), alls.end()), alls.end());
   for(auto item: add) {
       int pos = find(item.x);
       a[pos] += item.y;
   }
   for(int i = 0; i<alls.size(); i++) {
       s[i] = s[i-1] + a[i];
   }
   for(auto item: query) {
       int l = find(item.x);
       int r = find(item.y);
       printf("%d\n", s[r]-s[l-1]);
   }
}