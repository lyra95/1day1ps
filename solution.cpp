// 20210416
// programmers
// level3
// 입국심사
// https://programmers.co.kr/learn/courses/30/lessons/43238

#define assert(x) if(!(x)) __debugbreak();
#include <vector>

// solution
typedef long long answerType;

answerType solution(int n, std::vector<int> times)
{
    long long answer;
    return 28;
}

// test
class Test
{
    public: struct TestInput
    {
        int n;
        std::vector<int> times;
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
        std::vector<int> x{7,10};
        TestInput t{6,x};
        push(t, 28LL);
        for(int i=0;i<test_cases.size();i++)
        {
            assert( answers[i] == solution( test_cases[i].n , test_cases[i].times ));
        }
    }
};