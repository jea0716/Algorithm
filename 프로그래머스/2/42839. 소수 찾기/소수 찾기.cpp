#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer, max_num;
bool visited[10];
bool num[10000000];
vector<int> arr;

void solve(int cnt, int n, string tmp, string s) {
    if(cnt == n) {
        int tmp_num = stoi(tmp);
        if(!num[tmp_num]) {
            arr.push_back(tmp_num);
            num[tmp_num] = 1;
            if(tmp_num > max_num) max_num = tmp_num;
        }
        return ;
    }
    
    for(int i=0; i<s.length(); i++) {
        if(!visited[i]) {
            visited[i] = 1;
            solve(cnt + 1, n, tmp + s[i], s);
            visited[i] = 0;
        }
    }
}

int solution(string numbers) {
    for(int i=1; i<=numbers.length(); i++) {
        solve(0, i, "", numbers);
    }
    
    bool prime[max_num + 1];
    for(int i=0; i<=max_num; i++) prime[i] = 0;
    
    prime[0] = prime[1] = 1;
    for(int i=2; i<=max_num; i++) {
        for(int j=i+i; j<=max_num; j=j+i) {
            prime[j] = 1;
        }
    }
    
    for(int i=0; i<arr.size(); i++) {
        if(!prime[arr[i]]) {
            answer++;
            cout << arr[i] << " ";
        }
    }
    
    return answer;
}