#include "solution.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Fill this out
using ANSERTYPE = vector<int>;   // for answer type

// Fill this out
struct INPUT_TYPE { // for input type
    vector<int> arr;
    ANSERTYPE run()
    {
        // Fill this out
        return solution(arr);
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
                // cout << "\tinput: " << p.first << endl;
                // cout << "\texpected: " << '\n' << ans << endl;
                // cout << "\tgot: " << '\n' << got << endl;
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
    t.push({{2,1,3,3}},{1,2});
    t.push({{3,4,4,2,5,2,5,5}},{3});
    t.push({{3,5,3,5,7,5,7}},{-1});
    t.run();
    return 0;
}