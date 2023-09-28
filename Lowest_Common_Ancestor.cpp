#include <bits/stdc++.h>
using namespace std;

class String
{
private:
    char *str;
    int len;

public:
    String() 
    {
        str = new char[1];
        str[0] = '\0';
        len = 0;
    }
    String(const char s[])
    {
        int n = strlen(s);
        str = new char[n + 1];
        strcpy(str, s);
        len = n;
    }
    String(String &s)
    {
        str = new char[s.len];
        strcpy(str, s.str);
        len = s.len;
    }
    void print()
    {
        cout << str << endl;
        cout << len << endl;
    }
};

int main()
{
    // default constructor
    String s;
    // parametrized cons
    String s2 = "Hello";
    // copy cons
    String s3 = s2;
    s.print();
    s2.print();
    s3.print();
}