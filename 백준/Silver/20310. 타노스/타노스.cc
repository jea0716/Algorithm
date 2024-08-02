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

    int A = 0, B = 0;
    for(int i=0; i<S.length(); i++) {
        if(S[i] == '0') A++;
        else B++;
    }

    A /= 2, B /= 2;

    for(int i=0; i<A; i++) cout << '0';
    for(int i=0; i<B; i++) cout << '1';
    cout << '\n';


    return 0;
}