#include<iostream> 


using namespace std;


int gvalue = 10;

int& getValue()
{
    return gvalue;
}

void fun(int& i);

void fun(const int& i)
{
    cout << "fun(const string &) called " << std::endl;
    auto nclv = i;
    fun(nclv);
}

void fun(int& i)
{
    cout << "fun(string &) called " << std::endl;
    //const string c_s = "xz";
    //fun(c_s);
}

int main()
{
    //string s = "a";
    const auto& cr = getValue();
    fun(cr);
    return 0;
}
