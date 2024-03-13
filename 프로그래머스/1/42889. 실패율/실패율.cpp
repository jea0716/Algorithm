#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, double> a, pair<int, double> b) {
    return (a.second > b.second);
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int players = stages.size();
    vector<pair<int, double>> status(N+1, pair<int, double>{0,0.0});
    for (int i=0; i<N+1; i++) {// 스테이지
        status[i].first = i+1;
    }
    for (auto stage : stages) {// 도달했지만 클리어 못한 수 
        status[stage-1].second += 1.0;
    }
    for (int i=0; i<N; i++) {
        int fail_player = status[i].second;
        status[i].second /= players;// 실패율로 갱신
        players -= fail_player;// 전체수에서 클리어 못한수 빼준다
    }
    status.pop_back();// N+1은 마지막 단계도 통관한것이기 때문에 빼준다.
    stable_sort(status.begin(), status.end(), compare);
    for (auto stage : status) {
        answer.push_back(stage.first);
    }
    return answer;
}