#include <iostream>
using namespace std;

const int array_size = 5;
void print_ary(int ary[])
{
  for (int i; i < array_size; i++) {
    cout << ary[i] << '\t';
  }
        cout<<endl;     
}

int main(int argc, char *argv[])
{
 unsigned int a = 0;
 unsigned int b = 1;
 int ary1[5];
 ary1[3] = 5;
 int ary2[5];

 print_ary(ary2);
 a = a>b?a-b:b-a;
  cout << a << endl << b << endl; 
  return 0;
}

