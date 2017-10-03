
#include "pointers.h"

//A string literal is statically allocated so that it is safe to return one from a function. For example:
const char* error_message(int i)
{ 
	return "range error";
}
//The memory holding range error will not go away after a call of error_message().
void pointers_basic();
void pointer_to_arrays();
void constants();
void references();

void pointers()
{
	pointers_basic();
	pointer_to_arrays();
	constants();
	references();
}

void pointers_basic()
{
	char c = 'a';
	char* p = &c; // p holds the address of

	int* pi; // pointer to int
	char** ppc; // pointer to pointer to char
	int* ap[15]; // array of 15 pointers to ints
	int (*fp)(char*); // pointer to function taking a char* argument; returns an int
	int* f(char*); // function taking a char* argument; returns a pointer to int

	float v[3]; // an array of three floats: v[0], v[1], v[2]
	char* a[32]; // an array of 32 pointers to char: a[0] .. a[31]

	int d2[10][20]; // d2 is an array of 10 arrays of 20 integers

	//----Array Initializers
	int v1[] = { 1, 2, 3, 4 };
	char v2[] = { 'a', 'b', 'c', 0 };


	//char v3[2] = { �a�, �b�, 0 }; // error: too many initializers
	char v4[3] = { 'a', 'b', 0 }; // ok

	int v5[8] = { 1, 2, 3, 4 };	// is equivalent to int v5[] = { 1, 2, 3, 4 , 0, 0, 0, 0 };

	// v4 = { �c�, �d�, 0 }; // error: no array assignment
	//A string literal is a character sequence enclosed within double quotes:
	"this is a string"; // of type const char
	//A string literal contains one more character than it appears to have; it is terminated by the null character �\0�

	//A string literal can be assigned to a char*. This is allowed because in previous definitions of C
	//and C++ , the type of a string literal was char*. Allowing the assignment of a string literal to a
	//char* ensures that millions of lines of C and C++ remain valid. It is, however, an error to try to
	//modify a string literal through such a pointer:

	char* pu = "Plato";
	pu[5];

	for (int ii = 0; pu[ii]!=0; ii++) {}

	// pu[4] = 'e'; // error: assignment to const; result is undefined
	//This kind of error cannot in general be caught until run-time, and implementations differ in their enforcement of this rule.


	char peep[] = "Zeno"; // p is an array of 5 char
	peep[0] = 'R'; // ok


	char alpha[] = "abcdefghijklmnopqrstuvwxyz"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//compiler will concatenate the strings

	L"angst"; // string of wide characters // const wchar_t

	//strlen() relies on zero to indicate end-of-string; strlen(p) returns the number of characters up to
	//and not including the terminating 0. This is all pretty low-level. The standard library vector
	//(�16.3) and string (Chapter 20) don�t suffer from this problem.

}// end of function pointers


void pointer_to_arrays()
{
	int v[] = { 1, 2, 3, 4 };

	int len = sizeof(v) / sizeof(v[0]);

	int* p1 = v; // pointer to initial element (implicit conversion)
	int* p2 = &v[0]; // pointer to initial element
	int* p3 = &v[4]; // pointer to one beyond last element

	char vc[] = "Annemarie";
	//&vc[1];
	char* p = vc; // implicit conversion of char[] to char*
	//++p;
	cout << strlen(p) << endl;
	cout << strlen(vc) << endl; // implicit conversion of char[] to char*
	//	vc = p; // error: cannot assign to array

	int vi[10];
	short vs[10];
	std::cout << &vi[0] << ' ' << &vi[1] << '\n';
	std::cout << &vs[0] << ' ' << &vs[1] << '\n';
	// 0x7fffaef0 0x7fffaef4
	// 0x7fffaedc 0x7fffaede


	int v1[10];
	int v2[10];
	int i1 = &v1[5]-&v1[3]; // i1 = 2
	int i2 = &v1[5]-&v2[3]; // result undefined
	int* p11 = v2+2; // p11 = &v2[2]
	int* p21 = &v1[5]-2; // *p21 undefined

}


void g(const int* p)
{
	// can�t modify *p here
}

void constants()
{
	const int model = 90; // model is a const
	const int v[] = { 1, 2, 3, 4 }; // v[i] is a const
	// const int x; // error: no initializer

	const int c1 = 1;
	const int c2 = 2;
	//const int c3 = my_f(3); // don�t know the value of c3 at compile time
	extern const int c4; // don�t know the value of c4 at compile time
	const int* p = &c2; // need to allocate space for c2

	//Symbolic constants should be used systematically to avoid ��magic numbers�� in code.

	char* pop;
	char s[] = "Gorm";
	const char* pc = s; // pointer to constant
	// pc[3] = 'g'; // error: pc points to constant
	pc = pop; // ok
	char *const cp = s; // constant pointer
	cp[3] = 'a'; // ok
	// cp = pop; // error: cp is constant
	const char *const cpc = s; // const pointer to const
	// cpc[3] = 'a'; // error: cpc points to constant
	// cpc = pop; // error: cpc is constant

	//The declarator operator that makes a pointer constant is *const. There is no const* declarator
	//operator, so a const appearing before the * is taken to be part of the base type. For example:
	char *const cprt = "yo"; // const pointer to char
	char const* pcrt; // pointer to const char
	const char* pc2rt; // pointer to const char

	int a = 1;
	const int c = 2;
	const int* p15 = &c; // ok
	const int* p25 = &a; // ok
	// int* p35 = &c; // error: initialization of int* with const int*
	//*p35 = 7; // try to change the value of c

	//By declaring a pointer argument const, the function is prohibited from modifying the object pointed to. For example:
	//char* strcpy(char* p, const char* q) // cannot modify *q

}

void references()
{
	//A reference is an alternative name for an object.
	int i = 1;
	int& r = i; // r and i now refer to the same int
	int x = r;	// x = 1
	r = 2;			// i = 2

	//To ensure that a reference is a name for something (that is, bound to an object), we must initialize the reference.
	int& r1 = i;			// ok: r1 initialized
	int& r2;					// error: initializer missing
	extern int& r3;		// ok: r3 initialized elsewhere

	// no operator operates on a reference.
	int ii = 0;
	int& rr = ii;
	rr++; // ii is incremented to 1
	int* pp = &rr; // pp points to ii

	// Initialization
	double& dr = 1; // error: lvalue needed
	const double& cdr = 1; // ok
	//The interpretation of this last initialization might be:
		//double temp = double(1); // first create a temporary with the right value
		//const double& cdr = temp; // then use the temporary as the initializer for cdr
	//A temporary created to hold a reference initializer persists until the end of its reference�s scope.


}


void void_pointers()
{
	//A pointer of any type of object can be assigned to a variable of type void*, a void* can be assigned
	//to another void*, void*s can be compared for equality and inequality, and a void* can be explicitly
	//converted to another type.

	void* pv = pi; // ok: implicit conversion of int* to void*
	*pv; // error: can�t dereference void*
	pv++; // error: can�t increment void* (the size of the object pointed to is unknown)
	int* pi2 = static_cast<int*>(pv); // explicit conversion back to int*
	// double* pd1 = pv; // error
	// double* pd2 = pi; // error
	double* pd3 = static_cast<double*>(pv); // unsafe

	//The primary use for void* is for passing pointers to functions that are not allowed to make
	//assumptions about the type of the object and for returning untyped objects from functions. To use
	//such an object, we must use explicit type conversion.

	//Occurrences of void*s at higher levels of the system should be viewed with suspicion because they
	//are likely indicators of design errors.
}
