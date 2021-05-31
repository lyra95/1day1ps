#include <string>
#include <vector>
#include <map>
using namespace std;

map<char,char> flip{
    {'<', '>'},
    {'>', '<'}
};

map<char,int> dir{
    {'<',-1},
    {'>',1}
};
inline bool is_escaped(int block_size, int pos)
{
    return ( block_size < pos ) || ( pos < 1);
}

char access(string& block, int pos, vector<bool>& fliped)
{
    pos = pos-1;
    char ans = block[pos];
    if(fliped[pos])
        ans = flip[ans];
    return ans;
}

void one_step(string& block, int& pos, vector<bool>& fliped)
{
    char current = access(block, pos, fliped); // block[pos-1];
    fliped[pos-1] = !fliped[pos-1];
    // block.replace(pos-1,1,1,flip[current]);
    pos += dir[current];
}

long long solution(string block, int pos) {
    vector<bool> fliped(block.size(),false);
    long long answer = 0;
    while(!is_escaped(block.size(), pos))
    {
        one_step(block, pos, fliped);
        answer++;
    }
    return answer;
}