#include <iostream>
#include <string>
using namespace std;

class Play
{
public:
    Play(){}
    virtual ~Play(){}
    virtual void shoot(void) {
	cout << sTwoPipes << "\n" << sTwoPipes << endl;
    }

    virtual void pass(void) {
	cout << "|" << endl;
    }
    
private:
    string sTwoPipes = "||";
    
};

class Right : public Play
{
public:
    Right(){}
    virtual ~Right(){}
    virtual void shoot(void) {
	cout << " //" << endl << "//" << endl;
    }
};

class Left : public Right
{
public:
    Left(){}
    virtual ~Left(){}
    void shoot(void) {
	cout << "\\" << endl << " \\" << endl;
    }
};


int main(int argc, char *argv[])
{
    Play* p = new Right();
    p->shoot();
    p->pass();
    delete p;
    p = nullptr;
    p = new Left();
    p->pass();
    p->shoot();
    return 0;
}
