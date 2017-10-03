// datatypes.cpp : Defines the entry point for the console application.
//

#include "pointers.h"

// The #include statement is basically like a copy/paste operation. The compiler will "replace" the #include line with the actual contents of the file you're including when it compiles the file.
// http://www.cplusplus.com/forum/articles/10627/
/*
If, for example, class A uses class B, then class B is one of class A's dependencies. Whether it can be forward declared or needs to be included depends on how B is used within A:
		- do nothing if: A makes no references at all to B
		- do nothing if: The only reference to B is in a friend declaration
		- forward declare B if: A contains a B pointer or reference: B* myb;
		- forward declare B if: one or more functions has a B object/pointer/reference as a parementer, or as a return type: B MyFunction(B myb);
		- #include "b.h" if: B is a parent class of A
		- #include "b.h" if: A contains a B object: B myb;
*/

// A circular dependency is when two (or more) classes depend on each other. Use forward declarations to avoid circular dependencies

int x; // global x

/*
C++ has a set of fundamental types corresponding to the most common basic storage units of a
computer and the most common ways of using them to hold data:
§4.2 A Boolean type (bool)
§4.3 Character types (such as char)
§4.4 Integer types (such as int)
§4.5 Floating-point types (such as double)
In addition, a user can define
§4.8 Enumeration types for representing specific sets of values (enum)
There also is
§4.7 A type, void, used to signify the absence of information
From these types, we can construct other types:
§5.1 Pointer types (such as int*)
§5.2 Array types (such as char[])
§5.5 Reference types (such as double&)
§5.7 Data structures and classes (Chapter 10)
The Boolean, character, and integer types are collectively called integral types. The integral and
floating-point types are collectively called arithmetic types. Enumerations and classes (Chapter 10)
are called user-defined types because they must be defined by users rather than being available for
use without previous declaration, the way fundamental types are. In contrast, other types are called
built-in types.
*/

void datatypes()
{
	std::cout << 0xff << std::endl ;
	std::cout << 0xffff << std::endl ;
	std::cout << 0xffffffff << std::endl ;
	std::cout << 0xffffffffffff << std::endl ;
	std::cout << 0xffffffffffffffff << std::endl ;
	std::cout << sizeof(12) << std::endl ;
	std::cout << sizeof(12L) << std::endl ;
	std::cout << sizeof(12U) << std::endl ;
	char sx = 'a';
	char* sString = "string";
	cout<< "sizeof(sString \t) "<< sizeof(sString) << endl;
	//int x =0;
	unsigned int y = 1;
	long z = 2;
	unsigned long a = 3;
	short b = 1;
	// In 16-bit system, int is represented by 16 bits and range ( -2^15 to 2^15) and long is represented by 32 bits and range ( -2^31 to 2^31)
	std::cout << sizeof(x) << "\t" << sizeof(y) << "\t" << sizeof(z) << "\t" << sizeof(a) << "\t" << sizeof(b) << "\t" << std::endl;

	//The char type is supposed to be chosen by the implementation to be the most suitable type for
	//holding and manipulating characters on a given computer; it is typically an 8-bit byte. Similarly,
	//the int type is supposed to be chosen to be the most suitable for holding and manipulating integers
	//on a given computer; it is typically a 4-byte (32-bit) word.

	//When needed, implementation-dependent aspects about an implementation can be found in <limits>
	cout << "largest float == " << numeric_limits<float>::max() << ", char is signed == " << numeric_limits<char>::is_signed << endl;

	//--- void 
	// void x; // error: there are no void objects
//	void f(); // function f does not return a value (§7.3)
//	void* pv; // pointer to object of unknown type (§5.6)

	//----Enumerators
	//The range of an enumeration holds all the enumeration’s enumerator values rounded up to the nearest
	//larger binary power minus 1. The range goes down to 0 if the smallest enumerator is non-negative
	//and to the nearest lesser negative binary power if the smallest enumerator is negative. 

	enum e1 { dark, light }; // range 0:1
	enum e2 { f_f = 3, g = 9 }; // range 0:15
	enum e3 { min = -10, max = 1000000 }; // range -1048576:1048575

	enum flag { x_x=1, y_y=2, z_z=4, e=8 }; // range 0:15
	// flag f1 = 5; // type error: 5 is not of type flag
	flag f2 = flag(5); // ok: flag(5) is of type flag and within the range of flag
	flag f3 = flag(z_z|e); // ok: flag(12) is of type flag and within the range of flag
	flag f4 = flag(99); // undefined: 99 is not within the range of flag

	///-----Declarations
	
//	char ch;
	string s;
	int count = 1;
	const double pi = 3.1415926535897932385;
//	extern int error_number;
//	char* yo;
	int* hell = nullptr;
	char* name = "Njal";
	char months[4]={'J'};
	char* other_name = &(*name);
	char* season[] = { "spring", "summer", "fall", "winter" };
	struct Date { int d, m, y; };
	//int day(Date* p) { return p->d; }
//	double sqrt(double);
	//template<class T> T abs(T a) { return a<0 ? -a : a; }
	typedef complex<short> Point;
	struct User;
	enum Beer { Carlsberg, Tuborg, Thor };
	//namespace NS { int a; }

	//Of the declarationsabove, only
	//double sqrt(double);
	//extern int error_number;
	//struct User;
	//are not also definitions; that is, the entity they refer to must be defined elsewhere. 


	//There must always be exactly one definition for each name in a C++ program. However, there can be many declarations. All declarations of an entity must

//	int count;
	//int count; // error: redefinition
//	extern int error_number;
	//extern short error_number; // error: type mismatch

//	extern int error_number;
//	extern int error_number;

	//A declaration consists of four parts: an optional ‘‘specifier,’’ a base type, a declarator, and an
	//optional initializer. Except for function and namespace definitions, a declaration is terminated by a semicolon. 

	char* kings[] = { "Antigonus", "Seleucus", "Ptolemy" };
	// Here, the base type is char, the declarator is *kings[], and the initializer is ={...}.
	// A specifier is an initial keyword, such as virtual (§2.5.5, §12.2.6) and extern (§9.2), that specifies some non-type attribute of what is being declared.


	//---Scope
	//For a name declared in a function (often called a local name), that scope extends
	//from its point of declaration to the end of the block in which its declaration occurs. A block is a
	//section of code delimited by a { } pair.

	//A name is called global if it is defined outside any function, class (Chapter 10), or namespace
	//(§8.2). The scope of a global name extends from the point of declaration to the end of the file in
	//which its declaration occurs

	//That is, a name can be redefined to refer to a different entity
	//within a block. After exit from the block, the name resumes its previous meaning. For example:

	//void f()
	//{
	//	int x; // local x hides global x
	//x = 1; // assign to local x
	//{
	//	int x; // hides first local x
	//	x = 2; // assign to second local x
	//}
	//x = 3; // assign to first local x
	//}
	//int* p = &x; // take address of global x

	//Function argument names are considered declared in the outermost block of a function, so
	//void f5(int x)
	//{
	//int x; // error
	//}

	// Local variables are not initialized by default


	//there is a need for a name for
	//‘‘something in memory.’’ This is the simplest and most fundamental notion of an object. That is,
	//an object is a contiguous region of storage; an lvalue is an expression that refers to an object. The
	//word lvalue was originally coined to mean ‘‘something that can be on the left-hand side of an
	//assignment.’’ However, not every lvalue may be used on the left-hand side of an assignment; an
	//lvalue can refer to a constant (§5.5). An lvalue that has not been declared const is often called a
	//modifiable lvalue.

	// Automatic objects - created when its definition is encountered and destroyed when its name goes out of scope 
	// Static objects - Objects declared in global or namespace scope and statics declared in functions or classes are created and initialized once (only) and ‘‘live’’ until the program terminates
	
	
	
}

