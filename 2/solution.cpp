// Date  : 2021 May 24
// Source: 비공개
// Level : 2
// Name  : 비공개
// URL   : 비공개
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

int count(string row, char c)
{
    int ans = 0;
    for(auto x:row)
    {
        ans += ( x == c);
    }
    return ans;
}

map<char,int> helper(string row, set<char>& kinds)
{
    map<char,int> ans{};
    for(char c:kinds)
    {
        ans[c] += count(row, c);
    }
    return ans;
}

bool is_used(map<char,int>& row)
{
    int ans = 0;
    for(auto& p:row)
    {
        ans += p.second;
    }
    return ans > 0;
}

bool match(vector<string>& card, string word)
{
    if(word.size()<3)
        return false;
    bool ans = false;
    
    set<char> kinds{};
    for(auto c:word)
        kinds.emplace(c);
    //sort(word.begin(),word.end());
    map<char,int> first = helper(card[0], kinds);
    map<char,int> second = helper(card[1], kinds);
    map<char,int> third = helper(card[2], kinds);

    if( !is_used(first) || !is_used(second) || !is_used(third) )
        return false;
    
    map<char,int> word_map{};
    for(auto c: word)
    {
        word_map[c] += 1;
    }

    for(auto& p: word_map)
    {
        if( p.second > first[p.first] + second[p.first] + third[p.first])  // required number of char is more that number of char in cards
            return false;
    }
    return true;
}


vector<string> solution(vector<string> card, vector<string> word) {
    vector<string> answer = {};
    for(auto& w:word)
    {
        if(match(card, w))
            answer.push_back(w);
    }
    if(answer.empty())
        return {{"-1"}};
    return answer;
}