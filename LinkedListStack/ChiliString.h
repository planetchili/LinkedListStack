#pragma once

namespace chili
{
	void printfixed( const char* s,int w );
	void print( const char* s );
	void strcpy( const char* pSrc,char* pDst,int maxBufSize );
	void read( char* buf,int maxSize );
	int str2int( const char* s );
	void strrev( char* pl );
	void int2str( int val,char* buf,int size );
}