#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
    int answer = ((k - 1) * 2) % numbers.size() + 1;
    return answer;
}