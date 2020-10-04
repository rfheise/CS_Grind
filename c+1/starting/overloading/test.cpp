#include<iostream>
#include<stdio.h>

using namespace std;

class Test
{
    public:
    Test() {}
    Test(const Test &t)
    {
        cout<<"Copy constructor called "<<endl;
    }


    //returns a reference to an objects and not a new object so you have to add an & at the end of test
    //if you don't add it there it will return a copy of *this at the end and be more computationally expensive
    Test& operator = (const Test &t);

};

  Test& Test::operator =(const Test &t){
      cout<<"Assignment operator called "<<endl;
      return *this;
  }
// Driver code
int main()
{
    Test t1, t2;
    cout << "1st" << endl;
    t2 = t1;
    cout << "2nd" << endl;
    Test t3 = t1;
    // getchar();
    return 0;
}
