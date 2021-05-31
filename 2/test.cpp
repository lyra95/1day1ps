#include "solution.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Fill this out
using ANSERTYPE = vector<string>;   // for answer type

// Fill this out
struct INPUT_TYPE { // for input type
    vector<string> card;
    vector<string> word;
    ANSERTYPE run()
    {
        // Fill this out
        return solution(card, word);
    }
    
};
// Fill this out (optional)
ostream& operator<<(ostream& os, const INPUT_TYPE& data)
{
    os << "this is an input" << endl;
    return os;
}
// if << not defined for INPUT_TYPE


// if << not defined for ANSERTYPE
/*
ostream& operator<<(ostream& os, const ANSERTYPE& data)
{
    os << " ";
    return os;
}
*/

class Test
{
private:
    vector<pair<INPUT_TYPE,ANSERTYPE>> cases; 
public:
    void push(INPUT_TYPE input, ANSERTYPE ans)
    {
        cases.push_back({input,ans});
    }
    void run()
    {
        int n = cases.size();
        int passed = 0;
        cout << "test started" << endl;
        for(auto p : cases)
        {
            ANSERTYPE ans = p.second;
            ANSERTYPE got = p.first.run();
            if(ans == got)
            {
                passed++;
            }
            else
            {
                cout << "failed:" << endl;
                //cout << "\tinput: " << p.first << endl;
                //cout << "\texpected: " << '\n' << ans << endl;
                //cout << "\tgot: " << '\n' << got << endl;
            }
        }
        cout << "(" << passed << "/" << n << ") passed" << endl;
        cout << "test ended" << endl;
    }
    Test() = default;
    ~Test() = default;
};
int main()
{
    Test t;
    t.push({{"AABBCCDD", "KKKKJJJJ", "MOMOMOMO"}, {"AAAKKKKKMMMMM","ABCDKJ"}}, {"-1"});
    t.push({{"ABACDEFG", "NOPQRSTU", "HIJKLKMM"} ,	{"GPQM", "GPMZ", "EFU", "MMNA"}},{"GPQM","MMNA"});
    t.run();
    return 0;
}