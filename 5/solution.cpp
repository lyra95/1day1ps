// Date  : 2021 May 31
// Source: programmers
// Level : 3
// Name  : 여행경로
// URL   : https://programmers.co.kr/learn/courses/30/lessons/43164
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
vector<string> remove(vector<string> v, string item)
{
    vector<string> ans;
    bool bRemoved=false;
    for(int i=0;i<v.size();i++)
    {
        if((!bRemoved) && (v[i] == item))
        {
            bRemoved = true;
            continue;
        }
        ans.push_back(v[i]);
    }
    return ans;
}
void DFS(string root, map<string,vector<string>> m, vector<string> path, vector<vector<string>> &ans, int t)
{
    path.push_back(root);
    if(path.size() == t)
    {
        ans.push_back(path);
    }
    vector<string> adjacent{};
    for(auto x: m[root])
        adjacent.push_back(x);
    int n = m[root].size();
    for(int i = 0;i<n;i++)
    {
        auto city = adjacent[i];
        m[root] = remove(adjacent,city);
        DFS(city,m,path,ans,t);
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    map<string,vector<string>> m{};
    for(auto& t:tickets)
    {
        m[t[0]].emplace_back(t[1]);
    }

    for(auto& p:m)
    {
        sort(p.second.begin(),p.second.end());
    }

    string root = "ICN";
    vector<vector<string>> ans{};
    int t = tickets.size()+1;
    DFS(root,m,{},ans,t);
    return ans[0];
}