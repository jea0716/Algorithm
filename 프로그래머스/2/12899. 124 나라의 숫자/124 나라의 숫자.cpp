#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n) {
    string answer = "";
    
    vector<char> v;
    int tmp = n;
    while(tmp > 0) {
        if(tmp % 3 == 0) {
            v.push_back('4');
            tmp = tmp / 3 - 1;
        }
        else{
            v.push_back('0' + (tmp % 3));
            tmp /= 3;
        }
    }
    
    for(int i=v.size()-1; i>=0; i--) answer += v[i];
    if(tmp == 1) answer += '1';
    
    return answer;
}