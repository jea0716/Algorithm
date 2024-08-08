#include <iostream>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> num;

int main() {
    string s; cin >> s;
    string tmp = "";
    int sum = 0;
    for(int i=0; i<s.length(); i++) {
        if(s[i] == '-') {
            num.push_back(sum + stoi(tmp));
            tmp = "";
            sum = 0;
        }
        else if(s[i] == '+') {
            sum += stoi(tmp);
            tmp = "";
        }
        else tmp += s[i];
    }
    num.push_back(sum += stoi(tmp));

    int answer = num[0];
    for(int i=1; i<num.size(); i++) answer -= num[i];
    cout << answer << '\n';

    return 0;
}