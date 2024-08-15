#include <string>
#include <vector>
#include <iostream>

using namespace std;

char format_16[] = { '0', '1', '2', '3', '4', '5', '6', '7',
                 '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

vector<char> formatN;

string solution(int n, int t, int m, int p) {
    for(int i=0; i<n; i++) formatN.push_back(format_16[i]);
    int cnt = 0;
    int current_num = 0;
    int current_turn = 0;
    vector<char> v;
    
    string answer = "";
    while(cnt < t) {
        string tmp = "";
        int tmp_num = current_num;
        
        while(tmp_num >= n) {
            tmp += formatN[tmp_num % n];
            tmp_num /= n;
        }
        tmp += formatN[tmp_num];
        
        for(int i=tmp.length()-1; i>=0; i--) {
            if(current_turn == p - 1) {
                v.push_back(tmp[i]);
                cnt++;
            }
            
            current_turn = (current_turn + 1) % m;
        }
        
        current_num++;
    }
    
    for(int i=0; i<t; i++) answer += v[i];

    return answer;
}