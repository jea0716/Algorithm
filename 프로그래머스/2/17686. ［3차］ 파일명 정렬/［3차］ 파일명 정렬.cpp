#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct node {
    int loc;
    string head;
    int number;
    string tail;
};

vector<node> arr;

bool cmp(const node n1, const node n2) {
    if(n1.head == n2.head) {
        if(n1.number == n2.number) return n1.loc < n2.loc;
        return n1.number < n2.number;
    }
    return n1.head < n2.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    for(int i=0; i<files.size(); i++) {
        string head = "";
        string number = "";
        string tail = "";
        string tmp = "";
        for(int j=0; j<files[i].length(); j++) {
            char c = files[i][j];
            if(c >= '0' && c <= '9' && head == "") {
                head = tmp;
                tmp = "";
            }
            if((c < '0' || c > '9') && head != "" && number == "") {
                number = tmp;
                tmp = "";
            }
            if(c >= 'a' && c <= 'z') tmp += 'A' + c - 'a';
            else tmp += c;
        }
        if(number == "") number = tmp;
        else tail = tmp;
        arr.push_back({ i, head, stoi(number), tail });
    }
    
    sort(arr.begin(), arr.end(), cmp);
    
    for(int i=0; i<arr.size(); i++) {
        answer.push_back(files[arr[i].loc]);
    }
    
    return answer;
}