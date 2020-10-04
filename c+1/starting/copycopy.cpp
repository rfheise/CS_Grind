#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;

class Copy{
  public:
    //Copy class constructors
    Copy(int dat);
    //Copy copy constructor
    Copy(Copy &source);
    //Copy class deconstructor
    ~Copy();
    int * get_data(){return data;};
    void set_data(int * data){this -> data = data; };
  private:
    int *data;
};


//shallow copy
// Copy::Copy(Copy &source)
//   :data(source.data){
//     cout << "Performing Shallow Copy..." << endl;
// }

//deep Copy
// Copy::Copy(Copy &source){
//   cout << "Performing Deep Copy..." <<endl;
//   data = new int;
//   *data = *source.data;
// }

//not good because it makes it a global variable but it works for the example
string deep;
Copy::Copy(Copy &source){
  cout << "Deep or Shallow?" << endl << "Enter d or s" << endl;
  cin >> deep;
  cout << (deep.compare("s") == 0 ? "true" : "false") << endl;

  if(deep.compare("s") == 0){
    //shallow copy
    data = source.data;
  }
  else{
    //deep Copy
    int * x = new int;
    *x = *source.data;
    data = x;
  }

}
Copy::Copy(int dat){
  //creates a new int and makes its value dat
  int *x = new int;
  *x = dat;
  data = x;
}
Copy::~Copy(){
  delete data;
}

string compare(int b){
  return b? "true":"false";
}

int main(void){

  Copy *travis = new Copy(3);
  Copy *braden = new Copy(*travis);
  cout << "Travis' address "<< travis << endl;
  cout << "Braden's Address "<< braden <<endl;
  // cout << "Braden equals Traivs?" << (*braden == *travis ? "true" : "false") << endl;
  cout << "Braden's Address equals Travis' " << (braden == travis ? "true":"false") << endl;
  cout<< "Travis' Nubmer address "<< travis -> get_data() << endl;
  cout<< "Braden's Number address " << braden -> get_data() << endl;
  cout << "Braden's Number equals Traivs' " << compare(*(braden -> get_data()) == *(travis -> get_data())) << endl;
  cout << "Braden's Number Address equals Travis' " << compare(braden -> get_data() == travis -> get_data()) << endl;
  delete travis;
  //causes error in shallow copy because it will free the same address twice for the instance pointer variable data
  if(deep.compare("s") == 0){
    cout << "An error is about to happen because you shallow copied you doo doo head" << endl;
  }
  else{
    cout << "This will not cause an error because you were smart enough to deep copy" << endl;
  }
  delete braden;


}
