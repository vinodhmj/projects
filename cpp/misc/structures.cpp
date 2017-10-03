#include "stdafx.h"
#include "pointers.h"

struct address {
		char* name; // "Jim Dandy"
		long int number; // 61
		char* street; // "South St"
		char* town; // "New Providence"
		char state[2]; // ’N’ ’J’
		long zip; // 7974
	};
	//This defines a new type called address consisting of the items you need in order to send mail to someone.

//Structure objects are often accessed through pointers using the -> (structure pointer dereference) operator. For example:
void print_addr(address* p)
{
cout << p->name << '\n'
<< p->number << ' ' << p->street << '\n'
<< p->town << '\n'
<< p->state[0] << p->state[1] << ' ' << p->zip << '\n';
}


void operators();

void structures()
{
	//An array is an aggregate of elements of the same type. A struct is an aggregate of elements of (nearly) arbitrary types.

	// Variables of type address can be declared exactly as other variables, 
	// and the individual members can be accessed using the . (dot) operator.

	address jd;
	jd.name = "Jim Dandy";
	jd.number = 61;

	//The size of an object of a structure type is not necessarily the sum of the sizes of its members.
	//This is because many machines require objects of certain types to be allocated on architecturedependent boundaries or handle such objects much more efficiently if they are. 

	//Two structures are different types even when they have the same members. For example,
struct S1 { int a; };
struct S2 { int a; };
//are two different types, so
S1 x;
//S2 y = x; // error: type mismatch
//Structure types are also different from fundamental types, so
S1 x;
//int i = x; // error: type mismatch


operators();
}


void operators()
{
	//Unary operators and assignment operators are right-associative; all others are left-associative.
//For example, a=b=c means a=(b=c), a+b+c means (a+b)+c, and *p++ means *(p++), not (*p)++
	int x,y;
	int j = x = y; // the value of x=y is the value of x after the assignment
	int* p = &++x; // p points to x
	// int* q = &(x++); // error: x++ is not an lvalue (it is not the value stored in x)
	int* pp = &(x>y?x:y); // address of the int with the larger value

	// int x = f(2)+g(3); // undefined whether f() or g() is called first

	int v[]={1,2,3};
	int i = 1;
	v[i] = i++; // undefined result

	// The bitwise logical operators &, |, ^, ~, >>, and << are applied to objects of integer types – that is,
	// bool, char, short, int, long, and their unsigned counterparts. The results are also integers.

	//By definition, ++lvalue means lvalue+=1, which
	//again means lvalue=lvalue+1 provided lvalue has no side effects. The expression denoting the
	//object to be incremented is evaluated once (only). Decrementing is similarly expressed by the --
	//operator. The operators ++ and -- can be used as both prefix and postfix operators. The value of
	//++x is the new (that is, incremented) value of x. For example, y=++x is equivalent to y=(x+=1).
	//The value of x++, however, is the old value of x. For example, y=x++ is equivalent to
	//y=(t=x,x+=1,t), where t is a variable of the same type as x.


	// The value of *p++ = *q++ is *q. 
}



void new_delete()
{
	vector<int>* p = new vector<int>(n); // individual object
	int* q = new int[n]; // array
// ...
	delete p;
	delete[] q;

	//By default, the allocator throws a bad_alloc exception.
}