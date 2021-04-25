// 20210425
// codejam
// level4
// Median Sort
// https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d1284

#include <string>
#include <iostream>
#include <vector>
using namespace std;
// solution
vector<int> buff(4,0);

int ask_query(const int a,const int b,const int c){
    if(buff[0]==a && buff[1]==b && buff[2]==c) return buff[3];
    cout << a << ' ' << b << ' ' << c <<endl;
    int n;
    cin >> n;
    buff[0]=a;
    buff[1]=b;
    buff[2]=c;
    buff[3]=n;
    return n;
}

int ternery_search(vector<int> & v, int start, int end, int n){
    while(end-start>1){
        int t1 = (start*2 + end)/3;
        int t2 = (start + end*2)/3;

        int a = ask_query(v[t1],v[t2],n);

        if(a==v[t1]) end = t1;
        else if(a==v[t2]) start = t2;
        else{
            start = t1;
            end = t2;
        }
    }
    if(end-start==1){
        int a = ask_query(v[start],v[end],n);
        if(a==v[start]) return start;
        else if(a==v[end]) return end+1;
        else return end;
    }else{
        return start;
    }

}


int binary_search(vector<int> & v, int start, int end, int n){
    int mid = (start+end)/2;
    if(end-start>1 && start==0 && end==v.size()-1){
        int a1 = ask_query(v[start],v[mid],n);
        if(a1==n){
            end=mid;
        } else{
            int a2 = ask_query(v[mid],v[end],n);
            if(a2==n) start=mid;
            else{
                if(a1==v[mid]) return end+1;
                else return 0; 
            }
        }
    }
    while(end-start>1){
        mid = (start+end)/2;
        int a1 = ask_query(v[start],v[mid],n); 
        if(a1==n){
            end=mid;
        } else{
            start=mid;
        }
    }

    return end;
}

void helper(int n){
    vector<int> v{};
    int b = ask_query(1,2,3);
    if(b==1){
        v.push_back(3);
        v.push_back(1);
        v.push_back(2);
    }
    else if(b==2){
        v.push_back(3);
        v.push_back(2);
        v.push_back(1);
    }
    else{
        v.push_back(2);
        v.push_back(3);
        v.push_back(1);
    }
    
    for(int i=4;i<=n;i++){
        int pos = ternery_search(v,0,v.size()-1,i); // binary_search(v,0,v.size()-1,i);
        v.insert(v.begin()+pos, i);
    }

    for(int i=0;i<v.size();i++){
        cout << v[i] << ' ';
    }
    cout << endl;
}

void clear_buffer(){
    buff[0]=0;
    buff[1]=1;
    buff[2]=2;
    buff[3]=3;
}

int main() {
    int t,n,q;
    cin >> t >> n >> q;
    int cnt=1;

    for(cnt;cnt<=t;cnt++){
        clear_buffer();
        helper(n);
        int judge;
        cin >> judge;
        if(judge==-1) return 0;
    }
}
//test
/*
See the link.
*/
