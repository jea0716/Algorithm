#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF 987654321

int N, tmp;
vector<pair<int, int>> v;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;

    for(int i=1; i<=N; i++) {
        cin >> tmp;

        while(!v.empty()) {
            if(v.back().first > tmp) {
                cout << v.back().second << " ";
                break;
            }
            v.pop_back();
        }

        if(v.empty()) cout << "0 ";
        v.push_back({tmp , i });
    }

    cout << '\n';

    return 0;
}   