#include <string>
#include <vector>
#include <stack>

using namespace std;

bool check(string s)
{
    stack <bool> st;
    
    for(int i=0; i<s.length(); i++) 
    {
        if(s[i] == '(') st.push(true);
        else
        {
            if(st.empty()) return false;
            st.pop();
        }
    }
    
    return st.empty();
}

string solution(string p) {
    if(p.length() == 0) return p;
    string answer = "";
    
    string u = "", v = "";
    int left = 0, right = 0;
    
    for(int i=0; i<p.length(); i++)
    {
        if(p[i] == '(') left++;
        else right++;
        
        if(left == right)
        {
            u = p.substr(0, i + 1);
            v = p.substr(i + 1);
            break;
        }
    }
    
    if(check(u)) 
    {
        answer = u + solution(v);
    }
    else 
    {
        answer = "(" + solution(v) + ")";
        
        for(int i=1; i<u.length() - 1; i++)
        {
            answer += u[i] == '(' ? ')' : '(';
        }
    }
    
    return answer;
}