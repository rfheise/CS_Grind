#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
// :: is the scope resolution operator in c++
class Construct{
  public:
    static int workers;
    int count;
    Construct(string *named,int counter=0);
    Construct(string sleep,int x);
    string get_name(){return name;};
    Construct(const Construct &source)
      :name(source.name),count(source.count){
        workers ++;
      }
  private:
    string name;

};
int Construct::workers = 0;
Construct::Construct(string swipe,int x)
  :Construct(&swipe,x){

}
Construct::Construct(string *named,int counter)
//best way to initialize class variable else it will initialize to a garbage variable and then be initialized to the param
//this prevents double initialization
  :name(*named),count(counter)
  {
    workers++;
  }

int main(void){
  Construct high("I'm allocated in the stack and won't cause a memory leak 🤠",7);
  cout << high.get_name() << "," << high.count <<endl << endl;
  Construct dodo = Construct("I'm allocated on the stack too?",3);
  cout << dodo.get_name() << "," << dodo.count <<endl << endl;
  string *rough = new string("student");
  Construct *bruh = new Construct(rough,2);
  //points to the same object in memory so it will change the original
  //don't have to free because its created in the stack
  Construct *ha = bruh;
  ha -> count = 5;
  cout << "Doesn't Make Copy!!!" << endl;
  cout << "Initial " << bruh -> count << endl;
  cout << "Edited Copy " << ha -> count << endl << endl;
  cout << "Makes Copy 😎" << endl;
  string *swipe = new string("student");
  //have to delete previously allocated bruh or else you'll get a memory leak
  delete bruh;
  bruh = new Construct(swipe,2);
  //makes a copy and does not point to the same object in memory
  //calls copy constructor
  //will not change the original
  //don't have to free because its created in the stack
  Construct no = *bruh;
  no.count = 5;
  cout << "Initial " << bruh -> count << endl;
  cout << "Edited Copy " << no.count << endl << endl;
  cout << *rough << endl;
  cout << bruh->get_name() << "," << bruh -> count << endl;
  cout << "Workers "<< Construct::workers <<endl;
  //free allocated stack memory
  delete rough;
  delete bruh;
  delete swipe;
  cout << "Will it crash? Yes?!?!?!  "<< bruh << endl;
  //can't delete memory you already freed operating system will not let you do this
  //illegal
  delete bruh;
  cout << "NO!!!! It should have crashed this should not have happended 🤯🤬"<< endl;
}
