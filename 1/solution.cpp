// Date  : 2021 May 24
// Source: 비공개
// Level : 1
// Name  : 비공개
// URL   : 비공개
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> solution(vector<int> arr)
{
    sort(arr.begin(),arr.end());
    if(arr.empty()) return {};
    vector<int> answer{};
    int i=0;
    while(i<arr.size())
    {
        int tmp = arr[i];
        int j=0;
        while(i+j<arr.size())
        {
            if(arr[i+j]==tmp)
                j++;
            else
                break;
            
        }
        if(j==1)
            answer.push_back(tmp);
        i += j;
    }
    if(answer.empty())
        return {{-1}};
    
    return answer;
}