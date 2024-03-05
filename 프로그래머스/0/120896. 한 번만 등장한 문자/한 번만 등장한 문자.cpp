#include <string>
#include <vector>

using namespace std;

int arr[30];

string solution(string s) {
    string answer = "";
    for(int i=0; i<s.length(); i++) arr[s[i] - 'a']++;
    for(int i=0; i<30; i++) if(arr[i] == 1) answer += 'a' + i;
    return answer;
}