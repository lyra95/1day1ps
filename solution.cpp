// 20210508
// programmers
// level4
// 도둑질
// https://programmers.co.kr/learn/courses/30/lessons/42897
// test
// t.push({vector<int>{500,600,150,800,2500}}, 3100);
// solution
#include <string>
#include <vector>

using namespace std;

int helper(int start, vector<int>& money, bool is_odd)
{
    int ans = 0;
    for(int i=0;i<money.size()-is_odd;i+=2)
    {
        ans += money[(i+start)%money.size()];
    }
    return ans;
}

struct root
{
    int start;
    int money;
};

void next(root& r, const vector<int>& money)
{
    r.money = r.money - money[r.start] + money[(r.start-1+money.size())%(money.size())];
    r.start = (r.start+2)%money.size();
}

int solution(vector<int> money) {
    bool is_odd = money.size()%2 == 1;
    root first = root{0,helper(0,money,is_odd)};
    root second = root{1,helper(1,money,is_odd)};
    
    int answer = (first.money > second.money) ? first.money:second.money;
    if(!is_odd)
        return answer;
    
    for(int i=0;i<money.size();i++)
    {
        next(first,money);
        next(second,money);
        int temp = (first.money > second.money) ? first.money:second.money;
        if(temp > answer) answer = temp;
    }
    
    
    return answer;
}

typedef int answerType;
// test
class Test
{
    public: struct TestInput
    {
        vector<int> money;
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
            answerType ans = solution(  test_cases[i].money    );
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
