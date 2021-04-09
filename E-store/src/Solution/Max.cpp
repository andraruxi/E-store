#include"Max.h"

Max::Max():nr(0),judet("")
{

}

Max::Max(int n,string j):nr(n),judet(j)
{

}

int Max::getNr()
{
    return nr;
}

string Max::getJud()
{
    return judet;
}

void Max::setNr(int nr)
{
    this->nr=nr;
}

void Max::setJud(string judet)
{
    this->judet=judet;
}
