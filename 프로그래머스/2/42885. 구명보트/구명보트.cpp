#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    deque<int> v;
    for(int i=0; i<people.size(); i++) v.push_back(people[i]);
    sort(v.begin(), v.end());
    int s = 0, e = v.size() - 1, cnt = 0;
    while(!v.empty()) {
        if(v.size() > 1 && v[0] + v[v.size()-1] <= limit) {
            v.pop_front();
            v.pop_back();
            answer++;
        }
        else {
            v.pop_back();
            answer++;
        }
    }
    return answer;
}