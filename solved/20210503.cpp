// 20210503
// programmers
// level2
// 구명보트
// https://programmers.co.kr/learn/courses/30/lessons/42885

#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// solution
int solution(vector<int> people, int limit) {
    sort(people.begin(),people.end(), greater<int>());
    int front = 0;
    int back = people.size()-1;
    
    int ans=0;
    while(front < back)
    {
        int max = people[front];
        int min = people[back];
        if(max+min <= limit)
        {
            front++;
            back--;
        } else
        {
            front++;
        }
        ans++;
    }
    if(front==back) ans++;
    return ans;
}

typedef int answerType;
// test
class Test
{
    public: struct TestInput
    {
        vector<int> people;
        int limit;
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
            //[70, 50, 80, 50] 	100 	3
            TestInput t{vector<int>{70,50,80,50},100};
            int ans=3;
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
            answerType ans = solution(  test_cases[i].people, test_cases[i].limit    );
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

