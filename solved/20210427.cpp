// 20210427
// programmers
// level2
// 타겟넘버
// https://programmers.co.kr/learn/courses/30/lessons/43165

#include <vector>
#include <iostream>
using namespace std;
// solution
typedef int answerType;

struct Node
{
    int data;
    Node* next;
};

void dfs(Node* node, vector<int> & ways)
{
    if(node==nullptr) return;

    vector<int> ways_{};
    for(int t:ways)
    {
        ways_.push_back(t+node->data);
        ways_.push_back(t-node->data);
    }
    ways = ways_;
    dfs(node->next, ways);
}
int solution(vector<int> numbers, int target)
{
    Node* root = new Node{0,nullptr};
    Node* current = root;
    for(int x:numbers)
    {
        current->next = new Node{x,nullptr};
        current = current->next;
    }
    
    vector<int> ways(1);
    dfs(root->next,ways);

    int count = 0;
    for(int x:ways)
    {
        if(x==target) count++;
    }
    return count;
}

// test
class Test
{
    public: struct TestInput
    {
        vector<int> numbers;
        int target;
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
            vector<int> v{1,1,1,1,1};
            int target = 3;
            TestInput t{v,target};
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
            answerType ans = solution(  test_cases[i].numbers, test_cases[i].target   );
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

