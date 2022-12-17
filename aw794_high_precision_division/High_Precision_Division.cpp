#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> divide(vector<int> A, int b, int &r) {
    vector<int> C;
    for(int i = A.size()-1; i>=0; i--) {
        r = (r*10)+A[i];
        C.push_back(r/b);
        r = r%b;
    }
    reverse(C.begin(), C.end());
    while(C.size() > 1 && C.back() == 0) {
        C.pop_back();
    }
    return C;
}

int main() {
    string a;
    int b;
    cin>>a>>b;
    vector<int> A;
    for(int i = a.size()-1; i>=0; i--) {
        A.push_back(a[i]-'0');
    }
    int r = 0;
    vector<int> result = divide(A, b, r);
    for(int i = result.size()-1; i>=0; i--) {
        cout<<result[i];
    }
    puts("");
    cout<<r;
}