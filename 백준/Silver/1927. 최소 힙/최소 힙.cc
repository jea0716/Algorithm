#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, tmp;
priority_queue<int, vector<int>, greater<int>> q;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;

    while(N--) {
        cin >> tmp;
        if(tmp == 0) {
            if(q.empty()) cout << "0\n";
            else {
                cout << q.top() << '\n';
                q.pop();
            }
        }
        else {
            q.push(tmp);
        }
    }

    return 0;
}