// 20210505
// programmers
// level3
// 등굣길
// https://programmers.co.kr/learn/courses/30/lessons/42898

#include <vector>
#include <iostream>
using namespace std;
// solution
int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> noWater(m+1,vector<int>(n+1,1));
    for(auto p:puddles)
        noWater[p[0]][p[1]] = 0;
    auto i = noWater.end()- noWater.begin();
    for(int i=2;i<=m;i++)
        noWater[i][1] = noWater[i][1]*noWater[i-1][1];
    for(int j=2;j<=n;j++)
        noWater[1][j] = noWater[1][j]*noWater[1][j-1];
    
    for(int i=2;i<=m;i++)
    {
        for(int j=2;j<=n;j++)
        {
            noWater[i][j] = noWater[i][j]*(noWater[i-1][j]+noWater[i][j-1]);
        }
    }
    return noWater[m][n];
}

typedef int answerType;
// test
class Test
{
    public: struct TestInput
    {
        int m;
        int n;
        vector<vector<int>> puddles;
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
        // 4 	3 	[[2, 2]] 	4
        int m=4;
        int n=3;
        vector<vector<int>> p{{2,2}};
        int ans=4;
        push(TestInput{m,n,p},ans);
    }
    void test()
    {   
        helper();
        std::cout << "total " << test_cases.size() << " cases" << std::endl;
        int count = 0;
        for(int i=0;i<test_cases.size();i++)
        {
            answerType ans = solution( test_cases[i].m , test_cases[i].n, test_cases[i].puddles    );
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

