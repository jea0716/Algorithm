#include <string>
#include <vector>

using namespace std;

int solution(vector<string> order) {
    int answer = 0;
    for(int i=0; i<order.size(); i++) {
        if(
            order[i] == "iceamericano" ||
            order[i] == "americanoice" ||
            order[i] == "hotamericano" ||
            order[i] == "americanohot" ||
            order[i] == "americano" ||
            order[i] == "anything"
          ) answer += 4500;
        else answer += 5000;
    }
    return answer;
}