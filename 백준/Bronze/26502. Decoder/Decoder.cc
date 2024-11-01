#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

char origin[] = { 'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U', 'y', 'Y'};
char replacement[] = { 'y', 'Y', 'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    string s;
    int N; cin >> N;
    cin.ignore();

    for(int i=0; i<N; i++) {
        getline(cin, s);
        string tmp = "";
        for(int k=0; k<s.length(); k++) {
            bool check = false;
            for(int j=0; j<12; j++) {
                if(s[k] == replacement[j] && !check) {
                    tmp += origin[j];
                    check = true;
                }
            }
            if(!check) tmp += s[k];
        }

        cout << tmp << '\n';
    }

    return 0;
}   