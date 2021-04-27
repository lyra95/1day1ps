// 20210429
// programmers
// level2
// 위장
// https://programmers.co.kr/learn/courses/30/lessons/42578

#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
// solution
typedef int answerType;

int solution( vector<vector<string>> clothes )
{
    unordered_map<string,int> hash;
    for(auto &pair:clothes)
    {
        hash[pair[1]]++;
    }

    int ans = 1;
    for(auto &pair: hash)
    {
        ans *= (pair.second+1);
    }
    return ans-1;
}

// test
class Test
{
    public: struct TestInput
    {
        vector<vector<string>> clothes;
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
            vector<vector<string>> clothes{{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}};
            TestInput t{clothes};
            int ans = 5;
            push(t, ans);
        }
    }
    void test()
    {   
        helper();
        std::cout << "total " << test_cases.size() << " cases" << std::endl;
        int count = 0;
        for(int i=0;i<test_cases.size();i++)
        {
            answerType ans = solution(  test_cases[i].clothes  );
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

