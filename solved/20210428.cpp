// 20210428
// programmers
// level3
// 가장먼노드
// https://programmers.co.kr/learn/courses/30/lessons/49189

#include <vector>
#include <iostream>
#include <list>
#include <limits>
using namespace std;
// solution
typedef int answerType;

struct edgeInfo
{
    // vertex size
    int v_size;
    // arr stores edge info
    list<int> *arr;
    // constructor.
    edgeInfo(int n, vector<vector<int>> edge)
    :v_size(n), arr(new list<int>[n+1])
    {
        for(auto pair:edge)
        {
            arr[pair[0]].push_back(pair[1]);
            arr[pair[1]].push_back(pair[0]);
        }
    }
    ~edgeInfo()
    {
        delete[] arr;
    }
    // accessor; return the List of connected vertices with vertex v
    const list<int> & neighbors(int v)
    {
        // 1 <= v <= v_size
        return arr[v];
    }
};
int next(vector<bool> & visited, vector<int> & dist, int n)
{
    int min = 0;
    for(int i=1;i<=n;i++)
    {
        if( (!visited[i]) && dist[i]<dist[min]) min=i;
    }
    return min;
}
int solution(int n, vector<vector<int>> edge)
{
    edgeInfo e{n,edge};
    vector<bool> visited(n+1,false);
    vector<int> dist(n+1,INT_MAX);
    dist[1] = 0;

    int v=1;
    for(int i=0; i<n; i++)
    {
        v = next(visited, dist, n);
        if(v==0) break;
        for(int u:e.neighbors(v))
            if(dist[u] > dist[v]+1) dist[u] = dist[v]+1;
        visited[v] = true;
    }

    int max = INT_MIN;
    int count = 0;
    for(int i=1;i<=n;i++)
    {
        if(max<dist[i])
            max = dist[i], count = 1;
        else if(max==dist[i])
            count++;
    }
    return count;
}

// test
class Test
{
    public: struct TestInput
    {
        int n;
        vector<vector<int>> edge;
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
            int n = 6;
            vector<vector<int>> edge{{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}};
            TestInput t{n,edge};
            int ans = 3;
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
            answerType ans = solution(  test_cases[i].n, test_cases[i].edge    );
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

