#include <iostream>
#include <vector>
#include <algorithm>

#define x first
#define y second
using namespace std;
const int N = 1e5 + 10;
typedef pair<int, int> PII;
vector<PII> vPair;
vector<PII> result;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vPair.push_back({a, b});
    }
    sort(vPair.begin(), vPair.end());
    int start = -2e9, end = -2e9;
    for (auto e: vPair) {
        if (e.x > end) {
            if (end != -2e9) result.push_back({start, end});
            start = e.x;
            end = e.y;

        } else {
            end = max(end, e.y);
        }
    }
    if (start != -2e9 && end != -2e9) result.push_back({start, end});
    cout << result.size() << endl;
}