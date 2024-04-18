#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    vector <char> v;
    for(int i=0; i<number.length(); i++) {
        while (!v.empty() && v.back() < number[i] && k > 0) {
            k--;
            v.pop_back();
        }
        v.push_back(number[i]);
    }
    for(int i=0; i<k; i++) v.pop_back();
    string answer = "";
    for(int i=0; i<v.size(); i++) answer += v[i];
    return answer;
}