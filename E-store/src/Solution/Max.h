#include<iostream>
#include<string>
using namespace std;
class Max
{
    int nr;
    string judet;
public:
    Max();
    Max(int n,string j);

    int getNr();
    string getJud();

    void setNr(int nr);
    void setJud(string judet);

};
