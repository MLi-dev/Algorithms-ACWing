#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int N = 1e6+10;

vector<int> add(vector<int> A, vector<int> B) {
   vector<int> C;
   int t = 0;
   for(int i = 0; i<A.size(); i++) {
       t+=A[i];
       if(i<B.size()) {
           t+=B[i];
       }
       C.push_back(t%10);
       t/=10;
   }
   if(t) {
       C.push_back(1);
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
    for(int j = b.size()-1; j>=0; j--) {
        B.push_back(b[j]-'0');
    }
    vector<int> result;
    if(A.size()>B.size()) {
        result = add(A, B);
    } else {
        result = add(B, A);
    }
    for(int i = result.size()-1; i>=0; i--) {
        cout<<result[i];
    }
}