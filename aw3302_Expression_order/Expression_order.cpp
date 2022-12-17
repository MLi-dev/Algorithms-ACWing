#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <stack>

using namespace std;
const int N = 1e5 + 10;
stack<int> nums;
stack<char> ops;
unordered_map<char, int> h{{'+', 1},
                           {'-', 1},
                           {'*', 2},
                           {'/', 2}};

void eval() {
    int b = nums.top();
    nums.pop();
    int a = nums.top();
    nums.pop();
    char op = ops.top();
    ops.pop();
    int r = 0;
    switch (op) {
        case '+':
            r = a + b;
            break;
        case '-':
            r = a - b;
            break;
        case '*':
            r = a * b;
            break;
        case '/':
            r = a/b;
            break;

    }
    nums.push(r);
}

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            int k = i;
            int resp = 0;
            while(k<s.size() && isdigit(s[k])) {
                resp = resp*10+(s[k]-'0');
                k++;
            }
            i = k-1;

            nums.push(resp);
        } else if (s[i] == '(') {
            ops.push(s[i]);
        } else if (s[i] == ')') {
            while (ops.top() != '(') {
                eval();
            }
            ops.pop();
        } else {
            while (ops.size() && h[ops.top()] >= h[s[i]]) {
                eval();
            }
            ops.push(s[i]);
        }
    }
    while (ops.size()) {
        eval();
    }
    cout << nums.top() << endl;
}