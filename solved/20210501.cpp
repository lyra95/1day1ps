// 20210501
// programmers
// level2
// H-Index
// https://programmers.co.kr/learn/courses/30/lessons/42747

#include <vector>
#include <functional>
#include <iostream>
using namespace std;
// solution
int solution(vector<int> citations) {
    sort(citations.begin(),citations.end(),std::greater<int>());
    
    int h = citations.size();
    while(citations[h-1] < h) { h--; }
    return h;
}

typedef int answerType;
// test
class Test
{
    public: struct TestInput
    {
        vector<int> citations;
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
    void helper()
    {
        {
            // [3, 0, 6, 1, 5] 	3
            TestInput t{vector<int>{3,0,6,1,5}};
            int ans = 3;
            push(t,ans);
        }
    }
    void test()
    {   
        helper();
        std::cout << "total " << test_cases.size() << " cases" << std::endl;
        int count = 0;
        for(int i=0;i<test_cases.size();i++)
        {
            answerType ans = solution(  test_cases[i].citations    );
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

