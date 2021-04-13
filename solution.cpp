// 20210418
// programmers
// level2
// 프린터
// https://programmers.co.kr/learn/courses/30/lessons/42587

#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
// solution
typedef int answerType;
class Printer
{
    public:
        int location;
        queue<int> q;
        Printer(vector<int> priorities, int location)
        :location(location)
        {
            queue<int> q;
            for(int x :priorities)
            {
                q.push(x);
            }
            this->q = q;
        }
        void print()
        {
            q.pop();
            location--;
        }
        void delay()
        {
            int first = q.front();
            q.pop();
            q.push(first);
            (location == 0) ? location=q.size()-1 : location--;
        }
        int front()
        {
            return q.front();
        }
};
answerType solution( vector<int> priorities, int location )
{
    Printer p(priorities, location);
    sort(priorities.begin(),priorities.end());
    reverse(priorities.begin(),priorities.end());
    int cursor=0;
    while(p.location >= 0)
    {
        if(p.front() >= priorities[cursor])
        {
            p.print();
            cursor++;
        }
        else
        {
            p.delay();
        }
    }
    return cursor;
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
        helper();
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
    void helper()
    {
        {
            vector<int> priorities{2,1,3,2};
            int location=2;
            int answer=1;
            TestInput t{priorities,location};
            push(t,answer);
        }
        {
            vector<int> priorities{1,1,9,1,1,1};
            int location=0;
            int answer=5;
            TestInput t{priorities,location};
            push(t,answer);
        }
    }
};