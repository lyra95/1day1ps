// 20210506
// programmers
// level4
// 징검다리
// https://programmers.co.kr/learn/courses/30/lessons/43236
// test
// t.push({25,vector<int>{2,14,11,21,17},2},4);

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// count number of rocks to be deleted under condition interval >= 'interval'
int delete_rocks(int interval, const vector<int>& rocks, int distance){
    int from = 0;
    int to = interval;
    
    int delete_count = 0;
    int i = 0;
    while(i<rocks.size())
    {
        if(rocks[i] >= to)
        {
            from = rocks[i];
            to = from + interval;
        } else
            ++delete_count;
        ++i;
    }

    return delete_count;
}

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(),rocks.end());
    
    int from = 0;   // this is minimum posiible answer
    int to = distance/(rocks.size() - n + 1);   // this is maximum possible answer

    // binary search.
    while(to-from > 1)
    {
        int ans = (from+to)/2;
        if(delete_rocks(ans, rocks, distance) > n)
        {
            to = ans;
        } else
        {
            from = ans;
        }
    }

    if(delete_rocks(to,rocks,distance) > n)
        return from;
    else
        return to;
}
typedef int answerType;
// test
class Test
{
    public: struct TestInput
    {
        int distance;
        vector<int> rocks;
        int n;
    };

    private:
    vector<TestInput> test_cases;
    vector<answerType> answers;
    
    public:
    void push(TestInput t, answerType a)
    {
        test_cases.push_back(t);
        answers.push_back(a);
    }
    void test()
    {   
        std::cout << "total " << test_cases.size() << " cases" << std::endl;
        int count = 0;
        for(int i=0;i<test_cases.size();i++)
        {
            answerType ans = solution(  test_cases[i].distance, test_cases[i].rocks, test_cases[i].n    );
            try
            {
                if(ans == answers[i])
                {
                    std::cout << "succeeded " << i+1 << "th case" << std::endl;
                    count++;
                }
                else
                {
                    std::cout << "failed "<< i+1 << "th case, ans=" << answers[i] << " given=" << ans << std::endl;
                }

            }
            catch(...)
            {
                std::cout << "failed "<< i+1 << "th case, runtime error!" << std::endl;
            }
        }
        std::cout << "passed total " << count << " cases over " << test_cases.size() << " cases." << std::endl;
    }
};

