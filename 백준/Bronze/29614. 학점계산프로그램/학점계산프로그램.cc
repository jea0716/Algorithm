#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


float cnt, sum;
long long answer;
long long arr[10001];
string s;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> s;

    for(int i=0; i<s.length(); i++) {
        if(s[i] == '+') sum += 0.5;
        else {
            cnt++;
            if(s[i] == 'A') sum += 4.0;
            else if(s[i] == 'B') sum += 3.0;
            else if(s[i] == 'C') sum += 2.0;
            else if(s[i] == 'D') sum += 1.0;
            else if(s[i] == 'F') sum += 0.0;
        }
    }

    cout << sum / cnt << endl;

    return 0;
}   