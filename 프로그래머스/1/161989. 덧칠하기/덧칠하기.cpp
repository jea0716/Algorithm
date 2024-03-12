#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0, cur = 0;
    for(int i=0; i<section.size(); i++)
    {
        if (cur > section[i]) continue;
        answer++;
        cur = section[i] + m;
    }
    return answer;
}