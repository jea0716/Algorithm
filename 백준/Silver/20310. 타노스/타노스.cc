#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    string S;
    cin >> S;

    vector<char> v;
    for(int i=0; i<S.length(); i++) v.push_back(S[i]);
    vector<bool> vis(v.size(), 0);

    int A = 0, B = 0;
    for(int i=0; i<S.length(); i++) {
        if(S[i] == '0') A++;
        else B++;
    }

    A /= 2, B /= 2;

    for(int i=0; i<v.size(); i++) {
        if(B > 0 && v[i] == '1') {
            vis[i] = 1;
            B--;
        }
    }

    for(int i=v.size() - 1; i>=0; i--) {
        if(A > 0 && v[i] == '0') {
            vis[i] = 1;
            A--;
        }
    }

    for(int i=0; i<v.size(); i++) {
        if(vis[i] == 0) cout << v[i];
    }
    cout << '\n';


    return 0;
}