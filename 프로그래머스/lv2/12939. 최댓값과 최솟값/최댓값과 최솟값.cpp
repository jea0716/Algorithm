#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector <int> v;
    int p = 0;
    string tmp = "";
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == ' ')
        {
            v.push_back(stoi(tmp));
            tmp = "";
        }
        else
        {
            tmp += s[i];
        }
        if(i == s.length() - 1) v.push_back(stoi(tmp));
    }
    
    sort(v.begin(), v.end());
    
    answer = to_string(v.front()) + " " + to_string(v.back());
    
    return answer;
}