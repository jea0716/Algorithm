#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    vector<char> v;
    for(int i=0; i<s.length(); i++) v.push_back(s[i]);
    sort(v.rbegin(), v.rend());
    string answer = "";
    for(int i=0; i<v.size(); i++) answer += v[i];
    return answer;
}