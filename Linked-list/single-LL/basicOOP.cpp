#include<bits/stdc++.h>
using namespace std;

class info
{
    public:

    string name;
    int rollno;

    void printfunc_outside();
    void printfunc_inside()
    {
        cout << name << " " << rollno << "\n" ;
    }
};

class info2
{
    public:

    int id;

    info2()
    {
        cout << "Default constructor" <<"\n";
        id = 0;
    }

    info2(int temp)
    {
        cout << "Paramterized constructor" << "\n";
        id = temp;
    }
};

class info3
{
    public:

    info3()
    {
        cout << "Constructor" <<"\n";
    }

    ~info3()
    {
        cout << "Destructor" <<"\n";
    }
};

void info ::printfunc_outside()
{
    cout << rollno << " " << name << "\n";
}

int main()
{
    // Using info class showing basic class operations
    info object;
    object.name = "Kush";
    object.rollno = 23052247;
    object.printfunc_inside();
    object.printfunc_outside();

    cout << "\n";

    // Using info2 class to show default and parameterized constructor

    info2 first;
    cout << "num = " << " " << first.id << "\n";

    info2 second(1);
    cout << "num = " << " " << second.id << "\n";

    cout << "\n";

    //Using info3 to shoe destructor

    info3 ob1;
    info3 ob2;
    
}