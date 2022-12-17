#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int N = 1e6+10;

vector<int> mult(vector<int> A, int b) {
    vector<int> C;
    int t = 0;
    for(int i = 0; i<A.size(); i++) {
        t += A[i]*b;
        C.push_back(t%10);
        t = t/10;
    }
    if(t) {
        C.push_back(t);
    }
    while(C.size()>1 && C.back() ==0) {
        C.pop_back();
    }
    return C;
}

int main() {
    string a;
    int b;
    vector<int> A;
    cin>>a>>b;
    for(int i = a.size()-1; i>=0; i--) {
        A.push_back(a[i]-'0');
    }
    vector<int> result = mult(A, b);
    for(int i = result.size()-1; i>=0; i--) {
        cout<<result[i];
    }
}