#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N, tmp;

vector<char> v;
vector<int> stack;

int main() {
    cin >> N;

    // for(int i=N; i>=1; i--) v.push_back(i);

    int idx = 1;

    for(int i=0; i<N; i++) {
        cin >> tmp;
        bool check = false;
        if(!stack.empty()) {
            for(int i=0; i<stack.size(); i++) {
                if(stack[i] == tmp) check = true;
            }
        }
        if(check) {
            while(stack.back() != tmp) {
                v.push_back('-');
                stack.pop_back();
            }
            v.push_back('-');
            stack.pop_back();
        }
        else {
            if(idx > N) {
                cout << "NO\n";
                return 0;
            }
            while(idx <= N && idx != tmp) {
                v.push_back('+');
                stack.push_back(idx++);
            }
            v.push_back('+');
            stack.push_back(idx++);
            v.push_back('-');
            stack.pop_back();
        }
    }

    for(int i=0; i<v.size(); i++) cout << v[i] << '\n';

    return 0;
}