#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>

using namespace std;

int N, M;
vector<char> v;
vector<char> str;

bool check() {
    int aeiou = 0;
    for(int i=0; i<N; i++) {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') aeiou++;
    }

    if(aeiou >= 1 && N - aeiou >= 2) return true;
    else return false;
}

void solve(int d) {
    if(str.size() == N && check()) {
        for(int i=0; i<N; i++) cout << str[i];
        cout << '\n';
    }

    for(int i=d; i<M; i++) {
        str.push_back(v[i]);
        solve(i + 1);
        str.pop_back();
    }

    return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;

    char c;
    for(int i=0; i<M; i++) {
        cin >> c;
        v.push_back(c);
    }

    sort(v.begin(), v.end());
    solve(0);

    return 0;
}