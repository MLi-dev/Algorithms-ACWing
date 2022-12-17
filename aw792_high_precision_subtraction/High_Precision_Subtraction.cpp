#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int N = 1e5+10;

bool comp(vector<int> A, vector<int> B) {
    if(A.size() != B.size()) {
        return A.size() > B.size();
    }
    for(int i = A.size()-1; i>=0; i--) {
        if(A[i] != B[i]) {
            return A[i]>B[i];
        }
    }
    return true;
}

vector<int> subt(vector<int> A, vector<int> B) {
    vector<int> C;
    int t = 0;
    for(int i = 0; i<A.size(); i++) {
        t = A[i]-t;
        if(i<B.size()) {
            t = t-B[i];
        }
        C.push_back((t+10)%10);
        if(t<0) t = 1;
        else t = 0;
    }
    while(C.size()>1 && C.back() == 0) {
        C.pop_back();
    }
    return C;
}

int main() {
    string a, b;
    vector<int> A, B;
    cin>>a>>b;
    for(int i = a.size()-1; i>=0; i--) {
        A.push_back(a[i]-'0');
    }
    for(int i = b.size()-1; i>=0; i--) {
        B.push_back(b[i]-'0');
    }
    vector<int> result;
    if(comp(A, B)) {
        result = subt(A, B);
    } else {
        result = subt(B, A);
        cout<<"-";
    }
    for(int i = result.size()-1; i>=0; i--) {
        cout << result[i];
    }
}