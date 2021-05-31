#include "solution.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Fill this out
using ANSERTYPE = int;   // for answer type

// Fill this out
struct INPUT_TYPE { // for input type
    string S1;
    string S2;
    ANSERTYPE run()
    {
        // Fill this out
        return solution(S1, S2);
    }
    
};
// Fill this out (optional)
ostream& operator<<(ostream& os, const INPUT_TYPE& data)
{
    os << "\t\tthis is an input" << endl;
    os << "\t\t" << data.S1 << endl;
    os << "\t\t" << data.S2 << endl;
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
                cout << "\tinput: \n" << p.first << endl;
                cout << "\texpected: " << '\n' << ans << endl;
                cout << "\tgot: " << '\n' << got << endl;
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
    int head = 0;
    Node* root = make("w",0,head);
    int n = num_blacks(root);
    Test t;
    t.push({"ppwwwbpbbwwbw","pwbwpwwbw"},640);
    t.push({"b","w"},1024);
    t.run();
    return 0;
}