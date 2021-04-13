// 20210416
// programmers
// level3
// 입국심사
// https://programmers.co.kr/learn/courses/30/lessons/43238
#include <vector>
#include <algorithm>
// solution
typedef long long answerType;
#include <climits>

bool is_capable(const long long n, const long long time, const std::vector<int> &times)
{
    long long acc=0;
    for(int ability:times)
    {
        acc += time/(long long)ability;
    }

    return acc >= n;
}
long long solution(int n, std::vector<int> times)
{
    std::sort(times.begin(),times.end());
    long long start_time = 0;
    long long end_time = (long long)times[0]*n;
    while(end_time-start_time >= 1)
    {
        long long mid_time = start_time + (end_time-start_time)/2;
        if(is_capable(n, mid_time, times))
            end_time = mid_time;
        else
            start_time = mid_time + 1;
    }
    return start_time;
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
    std::vector<TestInput> test_cases;
    std::vector<answerType> answers;
    
    public:
    void push(TestInput t, answerType a)
    {
        test_cases.push_back(t);
        answers.push_back(a);
    }

    void test()
    {   
        std::vector<int> x{7,INT_MAX};
        TestInput t{INT_MAX,x};
        push(t, (long long)7*(INT_MAX-6));

        std::cout << "total " << test_cases.size() << " cases" << std::endl;
        int count = 0;
        for(int i=0;i<test_cases.size();i++)
        {
            answerType ans = solution( test_cases[i].n , test_cases[i].times );
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
