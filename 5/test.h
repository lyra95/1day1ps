#include "solution.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// print overloading for a vector.
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& data)
{
    os << "[ ";
    for(auto& x:data)
    {
        os << x << " , ";
    }
    os << " ]";
    return os;
}


// Fill this out
using ANSERTYPE = vector<string>;   // for answer type

// Fill this out
struct INPUT_TYPE { // for input type
    vector<vector<string>> tickets;
    ANSERTYPE run()
    {
        // Fill this out
        return solution(tickets);
    }
    // optional print function for INPUT_TYPE
    friend ostream& operator<<(ostream& os, const INPUT_TYPE& data);
};

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
        for(int i=0;i<cases.size();i++)
        {
            cout << "(" << i << ") " << "RUN" << endl;
            auto& p = cases[i];
            ANSERTYPE ans = p.second;
            ANSERTYPE got = p.first.run();
            if(ans == got)
            {
                passed++;
                cout << "(" << i << ") " << "PASS" << endl;
            }
            else
            {
                cout << "(" << i << ") " << "FAIL" << endl;
                cout << "\tinput: \n" << p.first << endl;
                cout << "\texpected: \n\t\t" << ans << endl;
                cout << "\tgot: \n\t\t" << got << endl;
            }
        }
        cout <<  "test ended: total (" << passed << "/" << n << ") passed" << endl;
    }
    Test() = default;
    ~Test() = default;
};