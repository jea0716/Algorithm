#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> arr;

string alpha[] = { "A", "E", "I", "O", "U" };

void recursive(int cnt, int n, string s) {
    if(s.length() == n) {
        arr.push_back(s);
        return ;
    }
    
    for(int i=0; i<5; i++) {
        recursive(cnt + 1, n, s + alpha[i]);
    }
}

int solution(string word) {
    int answer = 0;
    recursive(0, 1, "");
    recursive(0, 2, "");
    recursive(0, 3, "");
    recursive(0, 4, "");
    recursive(0, 5, "");
    sort(arr.begin(), arr.end());
    for(int i=0; i<arr.size(); i++) {
        if(arr[i] == word) {
            answer = i + 1;
        }
    }
    
    return answer;
}