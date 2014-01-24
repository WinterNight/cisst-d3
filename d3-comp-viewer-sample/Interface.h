#include <fstream>
using namespace std;

#define INTERNAL 0;
#define NONINTERNAL 1;
class Interface
{
  private:
    string name;
    int type;
  public:
    Interface(string i_name);
};
