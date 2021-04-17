// 20210420
// programmers
// level2
// 더맵게
// https://programmers.co.kr/learn/courses/30/lessons/42626
#include <queue>
#include <vector>
#include <iostream>
using namespace std;
// solution
typedef int answerType;

int solution(vector<int> scoville, int K) {
    priority_queue<int,vector<int>,greater<int>> q(scoville.begin(),scoville.end());
    int count=0;
    while(q.size()>1)
    {
        if(q.top()<K)
        {
            int first = q.top();
            q.pop();
            int second = q.top();
            q.pop();
            q.push(first+2*second);
            count++;
        }
        else
            return count;
    }
    return (q.top() < K) ? -1:count;
}

// test
class Test
{
    public: struct TestInput
    {
        vector<int> scoville;
        int K;
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
        TestInput t{{1, 2, 3, 9, 10, 12},7};
        int ans =2;
        push(t,ans);
    }

    void test()
    {   
        helper();
        std::cout << "total " << test_cases.size() << " cases" << std::endl;
        int count = 0;
        for(int i=0;i<test_cases.size();i++)
        {
            answerType ans = solution(  test_cases[i].scoville, test_cases[i].K    );
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

