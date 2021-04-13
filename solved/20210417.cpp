// 20210417
// programmers
// level2
// 다리를지나는트럭
// https://programmers.co.kr/learn/courses/30/lessons/42583

#include <vector>
#include <iostream>
#include <queue>
using namespace std;
// solution
typedef int answerType;
struct Bridge
{
    queue<int> bridge;
    int weight;
    int length;
    int capacity;
    Bridge(int l, int c): weight(0), length(l), capacity(c)
    {
        queue<int> q;
        for(int i=0; i<l; i++)
        {
            q.push(0);
        }
        bridge = q;
    }
    void push(int truck_weight)
    {
        weight += truck_weight - bridge.front();
        bridge.push(truck_weight);
        bridge.pop();
    }
    bool inline Permission(int truck_weight)
    {
        return capacity >= truck_weight - bridge.front() + weight;
    }
};

answerType solution(int bridge_length, int weight, vector<int> truck_weights)
{
    Bridge bridge(bridge_length, weight);
    int t=0;
    int i=0;
    while(i<truck_weights.size())
    {
        if(bridge.Permission(truck_weights[i]))
        {
            bridge.push(truck_weights[i]);
            i++;
        }
        else
            bridge.push(0);
        t++;
    }
    while(bridge.weight>0)
    { 
        bridge.push(0);
        t++;
    }
    return t;
}

// test
class Test
{
    public: struct TestInput
    {
        int length;
        int weight;
        vector<int> trucks;
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
            answerType ans = solution( test_cases[i].length, test_cases[i].weight, test_cases[i].trucks );
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
            int length=2;
            int weight=10;
            vector<int> trucks{7,4,5,6};
            Test::TestInput x{length, weight , trucks};
            int answer=8;
            push(x,answer);
        }
        {
            int length=100;
            int weight=100;
            vector<int> trucks{10};
            Test::TestInput x{length, weight , trucks};
            int answer=101;
            push(x,answer);
        }
        {
            int length=100;
            int weight=100;
            vector<int> trucks{10,10,10,10,10,10,10,10,10,10};
            Test::TestInput x{length, weight , trucks};
            int answer=110;
            push(x,answer);
        }
    }
};

