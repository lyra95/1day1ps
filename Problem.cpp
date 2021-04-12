#include <string>
#include <iostream>
#include <fstream>

#define message(x) cout << "\nsystem: " << (x) << "\nuser: "; 
using namespace std;

string getDate()
{
    std::ifstream f("./log/date.txt");
    if(f.fail())
    {
        std::cerr << "file does not exist" << std::endl;
        exit(100);
    }
    string date;
    f >> date;
    return date;
}

void updateDate(const string date)
{
    ofstream f("./log/date.txt");
    f << date;
}

class Problem
{
    public:
    explicit Problem()
    : date("00000000"), source("programmers"), level(0), name(""), link("")
    {
        string temp;
        // string current=getDate();
        message("type in the date (latest = " + getDate() + ")");
        std::getline(cin, temp);
        if(temp.size()) date = temp;

        message("type in the source of problem (default = programmers)");
        std::getline(cin, temp);
        if(temp.size()) source = temp;

        message("type in the level of difficulty (default = 0, easiest)");
        std::getline(cin, temp);
        if(temp.size()) level = stoi(temp);

        message("type in the name of problem (default = empty string)");
        std::getline(cin, temp);
        if(temp.size()) name = temp;
        message("type in the link of problem (default = empty string)");
        std::getline(cin, temp);
        if(temp.size()) link = temp;

        printInfo();
        message("creation succeeded. Going back to menu")
        cin >> temp;
    }
    void printInfo()
    {
        cout << "date: " << date << '\n'
            << "source: " << source << '\n'
            << "level: " << level << '\n'
            << "name: " << name << '\n'
            << "link: " << link << endl;
    }
    void createCPP()
    {
        updateDate(date);
        ofstream f("solution.cpp");
        f << "// " << date << endl;
        f << "// " << source << endl;
        f << "// " << level << endl;
        f << "// " << name << endl;
        f << "// " << link << endl;

        ifstream ifs("log/templete.txt");
        while(!ifs.eof())
        {
            string line;
            getline(ifs,line);
            f << line << endl;
        }
    }

    private:
    string date;
    string source;
    int level;
    string name;
    string link;
};

void MoveCPP()
{
    ifstream oldf("solution.cpp");

    string date = getDate();
    string newPath = "solved/"+date+".cpp";
    ofstream newf(newPath);


    string code;
    while(!oldf.eof())
    {
        getline(oldf, code);
        newf << code << endl;
    }
}