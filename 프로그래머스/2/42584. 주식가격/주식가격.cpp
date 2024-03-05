#include <string>
#include <vector>

using namespace std;

struct node {
    int spot, value;
};

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    int high_price = 0;
    vector<node> high_point;
    vector<node> pop_node;
    for(int i=0; i<prices.size(); i++) {
        if(prices[i] >= high_price) {
            high_price = prices[i];
            high_point.push_back({ i, prices[i] });
        }
        else {
            node pop_value = high_point[high_point.size()-1];
            while(pop_value.value > prices[i]) {
                pop_node.push_back(pop_value);
                high_point.pop_back();
                answer[pop_value.spot] = i - pop_value.spot;
                pop_value = high_point[high_point.size()-1];
            }
            while(!pop_node.empty()) {
                node tmp = pop_node[pop_node.size()-1];
                pop_node.pop_back();
            }
            high_price = prices[i];
            high_point.push_back({ i, prices[i] });
        }
    }
    
    while(!high_point.empty()) {
        node tmp = high_point[high_point.size()-1];
        high_point.pop_back();
        answer[tmp.spot] = prices.size() - 1 - tmp.spot;
    }
    return answer;
}