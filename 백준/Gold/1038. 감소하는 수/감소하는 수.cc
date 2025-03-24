#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int N, cnt;
long long ten;
vector<long long> v;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;

    for(int i=0; i<10; i++) { v.push_back(i); }
    cnt = v.size();
    for(int i=0; i<cnt; i++) {
        for(int j=1; j<10; j++) {
            if(v[i] < j) v.push_back(j * 10 + v[i]);
        }
    }

    for(int k=1; k<10; k++) {
        cnt = v.size();
        ten = 1;
        for(int i=0; i<k; i++) ten *= 10;
        for(int i=0; i<cnt; i++) {
            for(int j=k; j<10; j++) {
                if(v[i] >= ten && v[i] / ten < j) v.push_back(j * ten * 10 + v[i]);
            }
        }
    }

    sort(v.begin(), v.end());

    if(v.size() <= N) cout << "-1";
    else cout << v[N];
    cout << '\n';

    return 0;
}   