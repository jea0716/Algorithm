#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<pair<int, int>> v;

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    for(int i=0; i<book_time.size(); i++) {
        int s = stoi(book_time[i][0].substr(0, 2)) * 60 + stoi(book_time[i][0].substr(3, 5));
        int e = stoi(book_time[i][1].substr(0, 2)) * 60 + stoi(book_time[i][1].substr(3, 5));
        v.push_back({ s, e + 10 });
    }
    
    for(int i=0; i<24 * 60; i++) {
        int t = 0;
        for(int j=0; j<v.size(); j++) {
            if(i >= v[j].first && i < v[j].second) t++;
        }
        answer = answer > t ? answer : t;
    }
    
    return answer;
}