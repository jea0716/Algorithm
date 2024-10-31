#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    string s;
    cin >> s;

    for(int i=0; i<s.length(); i++) {
        if(
            s[i] == 'I' || s[i] == 'O' || s[i] == 'X' || s[i] == 'H' || 
            s[i] == 'N' || s[i] == 'S' || s[i] == 'Z'
        ) continue;
        else {
            cout << "NO\n";

            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}   