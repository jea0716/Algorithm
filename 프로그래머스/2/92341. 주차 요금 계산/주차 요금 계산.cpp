#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> ans;
    vector<pair<string, int>> tmp;
    map<string, int> in, out;

    for(string nxt : records) {
        int min = stoi(nxt.substr(0, 2)) * 60 + stoi(nxt.substr(3, 2));
        string num = nxt.substr(6, 4);
        string t = nxt.substr(11, 2);

        if(t == "IN") in[num] = min;
        else {
            out[num] += min - in[num];
            in.erase(num);
        }
    }

    for(auto nxt : in) {
        int min = 23*60+59;
        out[nxt.first] += min - in[nxt.first];
    }

    for(auto nxt : out) {
        int min = nxt.second - fees[0];
        int fee = fees[1];

        if(min > 0) {
            if(min % fees[2] == 0) fee += min / fees[2] * fees[3];
            else fee += (min / fees[2] + 1) * fees[3];
        }

        tmp.push_back({nxt.first, fee});
    }
    sort(tmp.begin(), tmp.end());

    for(auto nxt : tmp) ans.push_back(nxt.second);
    return ans;
}