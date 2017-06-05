#include "ChiliString.h"
#include <conio.h>

namespace chili
{
	void printfixed( const char* s,int w )
	{
		int n = 0;
		for( ; *s != 0; s++ )
		{
			n++;
			_putch( *s );
		}
		for( ; n < w; n++ )
		{
			_putch( ' ' );
		}
	}

	void print( const char* s )
	{
		for( ; *s != 0; s++ )
		{
			_putch( *s );
		}
	}

	void strcpy( const char* pSrc,char* pDst,int maxBufSize )
	{
		int n = 0;
		for( ; *pSrc != 0 && (n + 1 < maxBufSize); pSrc++,pDst++,n++ )
		{
			*pDst = *pSrc;
		}
		*pDst = 0;
	}

	void read( char* buf,int maxSize )
	{
		const char* const pEnd = buf + maxSize;
		for( char c = _getch(); c != 13 && (buf + 1 < pEnd); c = _getch(),buf++ )
		{
			_putch( c );
			*buf = c;
		}
		*buf = 0;
	}

	int str2int( const char* s )
	{
		// scan to start point
		const char* p = s;
		for( ; *p >= '0' && *p <= '9'; p++ );
		p--;

		int val = 0;
		int place = 1;
		// convert place values and accumulate
		for( ; p >= s; p-- )
		{
			val += (*p - '0') * place;
			place *= 10;
		}

		return val;
	}

	void strrev( char* pl )
	{
		// scan to start point
		char* pr = pl;
		for( ; *pr != 0; pr++ );
		pr--;

		for( ; pl < pr; pl++,pr-- )
		{
			const char temp = *pl;
			*pl = *pr;
			*pr = temp;
		}
	}

	void int2str( int val,char* buf,int size )
	{
		char* const pStart = buf;
		char* const pEnd = buf + size;
		for( ; val > 0 && (buf + 1 < pEnd); val /= 10,buf++ )
		{
			*buf = '0' + val % 10;
		}
		*buf = 0;
		strrev( pStart );
	}
}