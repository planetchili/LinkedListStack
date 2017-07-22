#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
#include <conio.h>
#include "ChiliString.h"
#include "Stack.h"

void test1()
{
	Stack s;
	s.Push( 5 );
	s.Push( 3 );
	if( s.Pop() == 3 && s.Pop() == 5 && s.Empty() )
	{
		chili::print( "    Test 1 passed!\n" );
	}
	else
	{
		chili::print( "*** Test 1 failed!\n" );
	}
}

void test2()
{
	Stack s;
	s.Push( 5 );
	s.Push( 3 );
	s.Push( 3 );
	s.Push( 3 );
	if( s.Size() == 4  )
	{
		chili::print( "    Test 2 passed!\n" );
	}
	else
	{
		chili::print( "*** Test 2 failed!\n" );
	}
}

void test3()
{
	Stack s;
	s.Push( 5 );
	s.Push( 3 );
	s.Pop();
	s.Push( 69 );
	s.Push( 69 );
	s.Push( 69 );
	s.Push( 69 );
	s.Pop();
	s.Pop();
	s.Pop();
	if( s.Size() == 2 )
	{
		chili::print( "    Test 3 passed!\n" );
	}
	else
	{
		chili::print( "*** Test 3 failed!\n" );
	}
}

void test4()
{
	Stack s;
	s.Push( 5 );
	s.Push( 3 );
	s.Pop();
	s.Pop();
	s.Pop();
	s.Pop();
	if( s.Size() == 0 )
	{
		chili::print( "    Test 4 passed!\n" );
	}
	else
	{
		chili::print( "*** Test 4 failed!\n" );
	}
}

void test5()
{
	Stack s;
	s.Push( 5 );
	s.Push( 3 );

	Stack s2 = s;
	s2.Pop();

	if( s.Size() == 2 && s2.Pop() == 5 )
	{
		chili::print( "    Test 5 passed!\n" );
	}
	else
	{
		chili::print( "*** Test 5 failed!\n" );
	}
}

void test6()
{
	Stack s;
	s.Push( 5 );
	s.Push( 3 );

	{
		Stack s2 = s;
		s2.Pop();
	}

	if( s.Size() == 2 && s.Pop() == 3 )
	{
		chili::print( "    Test 6 passed!\n" );
	}
	else
	{
		chili::print( "*** Test 6 failed!\n" );
	}
}

void test7()
{
	Stack s;
	s.Push( 5 );
	s.Push( 3 );

	Stack s2;
	s2 = s;
	s2.Pop();

	if( s.Size() == 2 && s2.Pop() == 5 )
	{
		chili::print( "    Test 7 passed!\n" );
	}
	else
	{
		chili::print( "*** Test 7 failed!\n" );
	}
}

void test8()
{
	Stack s;
	s.Push( 5 );
	s.Push( 3 );

	{
		Stack s2;
		s2 = s;
		s2.Pop();
	}

	if( s.Size() == 2 && s.Pop() == 3 )
	{
		chili::print( "    Test 8 passed!\n" );
	}
	else
	{
		chili::print( "*** Test 8 failed!\n" );
	}
}

void test9()
{
	Stack s;
	s.Push( 5 );
	s.Push( 3 );

	{
		Stack s2;
		s2.Push( 828374 );
		s2.Push( 3454 );
		s2 = s;
		s2.Pop();
	}

	if( s.Size() == 2 && s.Pop() == 3 )
	{
		chili::print( "    Test 9 passed!\n" );
	}
	else
	{
		chili::print( "*** Test 9 failed!\n" );
	}
}

int main()
{
	_CrtSetReportMode( _CRT_WARN,_CRTDBG_MODE_FILE );
	_CrtSetReportFile( _CRT_WARN,_CRTDBG_FILE_STDERR );
	_CrtSetReportMode( _CRT_ERROR,_CRTDBG_MODE_FILE );
	_CrtSetReportFile( _CRT_ERROR,_CRTDBG_FILE_STDERR );
	_CrtSetReportMode( _CRT_ASSERT,_CRTDBG_MODE_FILE );
	_CrtSetReportFile( _CRT_ASSERT,_CRTDBG_FILE_STDERR );
	
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();

	_CrtDumpMemoryLeaks();
	while( !_kbhit() );
	return 0;
}