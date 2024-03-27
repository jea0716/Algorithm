#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {

    int answer = 1;

    unordered_map<string, int> type;
    for (int i = 0; i < clothes.size(); i++) {
        type[clothes[i][1]]++;
    }

    for (const auto& t : type) {
        answer *= t.second + 1;
    }

    answer -= 1;

    return answer;
}