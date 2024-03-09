#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int visited[10001];

vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;
    vector<int> v = numlist;
    while(answer.size() < numlist.size()) {
        int min = 99999;
        vector<int> list;
        for(int i=0; i<v.size(); i++) {
            if(abs(v[i] - n) < min && visited[v[i]] == 0) {
                min = abs(v[i] - n);  
                while(!list.empty()) visited[v[i]] = 0, list.pop_back();
                list.push_back(v[i]);
            } 
            else if(abs(v[i] - n) == min && visited[v[i]] == 0) list.push_back(v[i]);
        }
        sort(list.begin(), list.end());
        while(!list.empty()) {
            int tmp = list[list.size()-1];
            visited[tmp] = 1;
            list.pop_back();
            answer.push_back(tmp);
        }
    }
    return answer;
}