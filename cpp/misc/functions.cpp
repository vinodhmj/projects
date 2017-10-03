#include "stdafx.h"
#include "pointers.h"


//A function can be defined to be inline. For example:
inline int fac(int n)
{
	return (n<2) ? 1 : n*fac(n-1);
}
//The inline specifier is a hint to the compiler that it should attempt to generate code for a call of
//fac() inline rather than laying down the code for the function once and then calling through the
//usual function call mechanism. A clever compiler can generate the constant 720 for a call fac(6).
//The possibility of mutually recursive inline functions, inline functions that recurse or not depending
//on input, etc., makes it impossible to guarantee that every call of an inline function is actually
//inlined. The degree of cleverness of a compiler cannot be legislated, so one compiler might generate 720, another 6*fac(5), and yet another an un-inlined call fac(6).



//A local variable is initialized when the thread of execution reaches its definition. By default, this
//happens in every call of the function and each invocation of the function has its own copy of the
//variable. If a local variable is declared static, a single, statically allocated object will be used to
//represent that variable in all calls of the function. It will be initialized only the first time the thread
//of execution reaches its definition. For example:
void f(int a)
{
	while (a--) {
		static int n = 0; // initialized once
		int x = 0; // initialized n times
		cout << "n == " << n++ << ", x == " << x++ << '\n';
	}
}
//A static variable provides a function with ‘‘a memory’’ without introducing a global variable that might be accessed and corrupted by other functions

void pointers_to_function();

void functions()
{
	f(3);

	///declaring a pointer argument const tells readers that the value of an object pointed to by that argument is not changed by the function. For example:
	// int strlen(const char*); // number of characters in a C-style string
	// char* strcpy(char* to, const char* from); // copy a C-style string
	// int strcmp(const char*, const char*); // compare C-style strings

	//If an array is used as a function argument, a pointer to its initial element is passed. For example:
	//int strlen(const char*);
	//void f()
	//{
	//char v[] = "an array";
	//int i = strlen(v);
	//int j = strlen("Nicholas");
	//}
	//That is, an argument of type T[] will be converted to a T* when passed as an argument. This
	//implies that an assignment to an element of an array argument changes the value of an element of
	//the argument array. In other words, arrays differ from other types in that an array is not (and cannot be) passed by value.

	//void f(int);
	//void g()
	//{
	//void f(double);
	//f(1); // call f(double)
	//}
	//Clearly, f(int) would have been the best match for f(1), but only f(double) is in scope. 

	//Default arguments may be provided for trailing arguments only. For example:
	//int f(int, int =0, char* =0); // ok
	//int g(int =0, int =0, char*); // error
	//int h(int =0, int, char* =0); // error
	//Note that the space between the * and the = is significant (*= is an assignment operator; §6.2):
	//int nasty(char*=0); // syntax error
}


void pointers_to_function()
{
	void (*pf)(string); // pointer to void(string)
void f1(string); // void(string)
int f2(string); // int(string)
void f3(int*); // void(int*)

pf = &f1; // ok
//pf = &f2; // error: bad return type
//pf = &f3; // error: bad argument type
pf("Hera"); // ok
//pf(1); // error: bad argument type
//int i = pf("Zeus"); // error: void assigned to int
typedef void (*SIG_TYP)(int); // from <signal.h>
typedef void (*SIG_ARG_TYP)(int);
SIG_TYP signal(int, SIG_ARG_TYP);

typedef void (*PF)();
//PF edit_ops[] = { // edit operations
//&cut, &paste, &copy, &search
//};
//PF file_ops[] = { // file management
//&open, &append, &close, &write
//};

}


//Conditional Compilation [fct.cond]
//One use of macros is almost impossible to avoid. The directive #ifdef identifier conditionally
//causes all input to be ignored until a #endif directive is seen. For example,
//int f(int a
//#ifdef arg_two
//,int b
//#endif
//);
//produces
//int f(int a
//);