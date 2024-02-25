#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int sum = 0, mul = 1;
    int answer = 0;
    for(int i=0; i<num_list.size(); i++) {
        sum += num_list[i];
        mul *= num_list[i];
    }
    answer = sum * sum < mul ? 0 : 1;
    return answer;
}