#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<long long> num;
vector<char> sign;

long long calculate(char first, char second, char third)
{
    vector<long long> tmp_num = num;
    vector<bool> used(num.size(), 0);
    
    for(int i=0; i<sign.size(); i++)
    {
        int n1, n2;
        if(sign[i] == first)
        {
            n1 = i; 
            n2 = i + 1;
            
            while(used[n1]) n1--;
            while(used[n2]) n2++;
            
            if(first == '+') tmp_num[n1] = tmp_num[n1] + tmp_num[n2];
            if(first == '*') tmp_num[n1] = tmp_num[n1] * tmp_num[n2];
            if(first == '-') tmp_num[n1] = tmp_num[n1] - tmp_num[n2];
            
            used[n2] = true;
        }
    }
    
    for(int i=0; i<sign.size(); i++)
    {
        int n1, n2;
        if(sign[i] == second)
        {
            n1 = i; 
            n2 = i + 1;
            
            while(used[n1]) n1--;
            while(used[n2]) n2++;
            
            if(second == '+') tmp_num[n1] = tmp_num[n1] + tmp_num[n2];
            if(second == '*') tmp_num[n1] = tmp_num[n1] * tmp_num[n2];
            if(second == '-') tmp_num[n1] = tmp_num[n1] - tmp_num[n2];
            
            used[n2] = true;
        }
    }
    
    for(int i=0; i<sign.size(); i++)
    {
        int n1, n2;
        if(sign[i] == third)
        {
            n1 = i; 
            n2 = i + 1;
            
            while(used[n1]) n1--;
            while(used[n2]) n2++;
            
            if(third == '+') tmp_num[n1] = tmp_num[n1] + tmp_num[n2];
            if(third == '*') tmp_num[n1] = tmp_num[n1] * tmp_num[n2];
            if(third == '-') tmp_num[n1] = tmp_num[n1] - tmp_num[n2];
            
            used[n2] = true;
        }
    }
    
    if(tmp_num[0] < 0) tmp_num[0] *= -1;
    
    return tmp_num[0];
}

long long solution(string expression)
{
    long long answer = 0;
    
    string tmp = "";
    for(int i=0; i<expression.length(); i++)
    {
        char c = expression[i];
        if(c == '+' || c == '-' || c == '*')
        {
            num.push_back(stoll(tmp));
            sign.push_back(c);
            tmp = "";
        }
        else 
        {
            tmp += c;
        }
    }
    num.push_back(stoll(tmp));
    
    answer = max(answer, calculate('+', '-', '*'));
    answer = max(answer, calculate('+', '*', '-'));
    answer = max(answer, calculate('-', '+', '*'));
    answer = max(answer, calculate('-', '*', '+'));
    answer = max(answer, calculate('*', '+', '-'));
    answer = max(answer, calculate('*', '-', '+'));
    
    return answer;
}