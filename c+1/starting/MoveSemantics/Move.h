
#include <string>

using namespace std;

class Move{
  public:
    ~Move();
    Move(string s);
    Move(Move & source);
    Move(Move && source);
  private:
    string *str;
};
