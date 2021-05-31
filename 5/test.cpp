// test_cases
// {{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}} 	{"ICN", "JFK", "HND", "IAD"}
/*



  테스트 1

  
  입력값 〉
  	[["ICN", "JFK"], ["HND", "IAD"], ["JFK", "HND"]]

  
  기댓값 〉
  	["ICN", "JFK", "HND", "IAD"]

  
    실행 결과 〉
    	
  

  

  테스트 2

  
  입력값 〉
  	[["ICN", "SFO"], ["ICN", "ATL"], ["SFO", "ATL"], ["ATL", "ICN"], ["ATL", "SFO"]]

  
  기댓값 〉
  	["ICN", "ATL", "ICN", "SFO", "ATL", "SFO"]

  
    실행 결과 〉
  */  	
#include "test.h"

// Fill this out (optional)
// if << not defined for INPUT_TYPE
ostream& operator<<(ostream& os, const INPUT_TYPE& data)
{
    os << "\t\t" << data.tickets << endl;
    return os;
}

// if << not defined for ANSERTYPE
/*
ostream& operator<<(ostream& os, const ANSERTYPE& data)
{
    os << " ";
    return os;
}
*/
int main()
{
    Test t;
    t.push({{{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"}}},{"ICN", "ATL", "ICN", "SFO", "ATL", "SFO"});
    t.push({{{"ICN", "COO"}, {"ICN", "BOO"}, {"COO", "ICN"}, {"BOO", "DOO"}}},{});
    t.push({{{"ICN","A"},{"A","B"},{"A","C"},{"C","A"},{"B","C"}}},{});
    t.push({{{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}}},{"ICN", "JFK", "HND", "IAD"});
    
    // {{"ICN", "COO"}, {"ICN", "BOO"}, {"COO", "ICN"}, {"BOO", "DOO"}}
    
    t.run();
    return 0;
}