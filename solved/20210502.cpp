// 20210502
// programmers
// level2
// 카펫
// https://programmers.co.kr/learn/courses/30/lessons/42842

#include <vector>
#include <iostream>
using namespace std;
// solution
vector<int> solution(int brown, int yellow) {
    vector<int> answer(2);
    for(int width=1;width*width <= yellow;width++)
    {
        if(yellow%width!=0) continue;
        int height = yellow/width;
        if((width+2)*(height+2)==brown+yellow)
            return vector<int>{height+2,width+2};
    }
    return answer;
}

typedef vector<int> answerType;
// test
class Test
{
    public: struct TestInput
    {
        int brown;
        int yellow;
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
            TestInput t{24,24};
            vector<int> ans{8,6};
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
            answerType ans = solution(  test_cases[i].brown, test_cases[i].yellow );
            try
            {
                if(ans == answers[i])
                {
                    std::cout << "succeeded " << i+1 << "th case" << std::endl;
                    count++;
                }
                else
                {
                    std::cout << "failed "<< i+1 << "th case, ans=" << answers[i][0] << answers[i][1] << " given=" << ans[0] << ans[1] << std::endl;
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

