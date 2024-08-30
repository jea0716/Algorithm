#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct music {
    int time;
    string title;
};

vector<music> v;

vector<string> make_melody(string s) {
    vector<string> arr;
    arr.clear();
    string tmp = "";
    
    for(int i=0; i<s.length(); i++) 
    {
        if(s[i] == '#') 
            {
                arr.pop_back();
                tmp = "";
                tmp += s[i - 1];
                tmp += s[i];
                arr.push_back(tmp);
            }
            else 
            {   
                tmp = "";
                tmp += s[i];
                arr.push_back(tmp);
            }
    }
    
    return arr;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    vector<string> m_melody;
    string tmp = "";
    
    m_melody = make_melody(m);

    for(int i=0; i<musicinfos.size(); i++) 
    {    
        string info = musicinfos[i];
        int start = stoi(info.substr(0, 2)) * 60 + stoi(info.substr(3, 5));
        int end = stoi(info.substr(6, 8)) * 60 + stoi(info.substr(9, 11));
        int time = end - start;
        
        string tmp = "", title = "", melody_string;
        vector<string> melody;
        
        for(int j=12; j<info.length(); j++) 
        {
            if(info[j] == ',') 
            {
                title = info.substr(12, j - 12);
                melody_string = info.substr(j + 1);
            }
        }
        
        melody = make_melody(melody_string);
        
        int melody_length = melody.size();
        for(int i=melody.size(); i<time; i++) 
        {
            melody.push_back(melody[i % melody_length]);
        }
        while(melody.size() < time) 
        {
            int size = melody.size();
            for(int i=0; i<size; i++)
            {
                melody.push_back(melody[i]);
            }
        }
        while(melody.size() > time) 
        {
            melody.pop_back();
        }
        
        if(melody.size() >= m_melody.size())
        {
            for(int k=0; k<melody.size() - m_melody.size() + 1; k++)
            {
                bool check = true;
                for(int j=0; j<m_melody.size(); j++) 
                {
                    if(melody[k + j] != m_melody[j]) 
                    {
                        check = false;
                    }
                }
                if(check) 
                {
                    v.push_back({ time, title });
                }
            }
        }
    }
    
    if(v.empty()) 
    {
        answer = "(None)";
    }
    else
    {
        answer = v[0].title;
    }
    
    if(v.size() > 1) 
    {
        int max_time = v[0].time;
        for(int i=1; i<v.size(); i++)
        {
            if(max_time < v[i].time)
            {
                max_time = v[i].time;
                answer = v[i].title;
            }
        }
    }
    
    return answer;
}