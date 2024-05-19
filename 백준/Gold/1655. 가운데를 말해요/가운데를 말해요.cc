#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N, tmp, mid;
priority_queue<int, vector<int>, greater<int>> up_pq;
priority_queue<int> down_pq;

void solve() {

    return ;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;

    for(int i=0; i<N; i++) {
        cin >> tmp;

        if(i == 0) {
            mid = tmp;
        }
        else {
            if(mid > tmp) {
                down_pq.push(tmp);
                up_pq.push(mid);
            }
            else {
                up_pq.push(tmp);
                down_pq.push(mid);
            }

            if(up_pq.size() > down_pq.size()) {
                mid = up_pq.top();
                up_pq.pop();
            }
            else {
                mid = down_pq.top();
                down_pq.pop();
            }
        }
        cout << mid << "\n";
    }

    return 0;
}