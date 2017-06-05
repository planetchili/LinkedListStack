#pragma once

class Stack
{
public:
	void Push( int val );
	int Pop();
	int Size() const;
	bool Empty() const;
};