// 20210418
// programmers
// level2
// 프린터
// https://programmers.co.kr/learn/courses/30/lessons/42587

#include <vector>
#include <iostream>
using namespace std;
// solution
typedef int answerType;

answerType solution( vector<int> priorities, int location )
{
    int i = 0;
    while(true)
    {
        
    }
    return 0;
}

// test
class Test
{
    public: struct TestInput
    {
        vector<int> priorities;
        int location;
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
            answerType ans = solution(  test_cases[i].priorities, test_cases[i].location    );
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
