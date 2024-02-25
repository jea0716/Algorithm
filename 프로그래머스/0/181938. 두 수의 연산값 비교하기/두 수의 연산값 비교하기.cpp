#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    string tmp = to_string(a) + to_string(b);
    int answer = stoi(tmp) > 2 * a * b ? stoi(tmp) : 2 * a * b;
    return answer;
}