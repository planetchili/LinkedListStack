#pragma once

class Stack
{
private:
	class Element
	{
	public:
		Element( int val,Element* pNext )
			:
			val( val ),
			pNext( pNext )
		{}
		Element( const Element& src )
			:
			val( src.val )
		{
			if( src.pNext != nullptr )
			{
				pNext = new Element( *src.pNext );
			}
		}
		Element& operator=( const Element& ) = delete;
		int GetVal() const
		{
			return val;
		}
		Element* Disconnect()
		{
			auto pTemp = pNext;
			pNext = nullptr;
			return pTemp;
		}
		int CountElements() const
		{
			if( pNext != nullptr )
			{
				return pNext->CountElements() + 1;
			}
			else
			{
				return 1;
			}
		}
		~Element()
		{
			delete pNext;
			pNext = nullptr;
		}
	// there is a way to keep these private
	// by making Iterator a friend of Element
	// but it is not worth the hassle(hoff)
	// private:
		int val;
		Element* pNext = nullptr;
	};
public:
	class Iterator
	{
	public:
		Iterator() = default;
		Iterator( Element* pElement )
			:
			pElement( pElement )
		{}
		Iterator& operator++()
		{
			pElement = pElement->pNext;
			return *this;
		}
		int& operator*() const
		{
			return pElement->val;
		}
		bool operator!=( Iterator rhs ) const
		{
			return pElement != rhs.pElement;
		}
	private:
		Element* pElement = nullptr;
	};
	class ConstIterator
	{
	public:
		ConstIterator() = default;
		ConstIterator( const Element* pElement )
			:
			pElement( pElement )
		{}
		ConstIterator& operator++()
		{
			pElement = pElement->pNext;
			return *this;
		}
		const int& operator*() const
		{
			return pElement->val;
		}
		bool operator!=( ConstIterator rhs ) const
		{
			return pElement != rhs.pElement;
		}
	private:
		const Element* pElement = nullptr;
	};
public:
	Stack() = default;
	Stack( const Stack& src )
	{
		*this = src;
	}
	Stack& operator=( const Stack& src )
	{
		if( &src != this )
		{
			if( !Empty() )
			{
				delete pTop;
				pTop = nullptr;
			}

			if( !src.Empty() )
			{
				pTop = new Element( *src.pTop );
			}
		}
		return *this;
	}
	~Stack()
	{
		delete pTop;
		pTop = nullptr;
	}
	void Push( int val )
	{
		pTop = new Element( val,pTop );
	}
	int Pop()
	{
		if( !Empty() )
		{
			const int tempVal = pTop->GetVal();
			auto pOldTop = pTop;
			pTop = pTop->Disconnect();
			delete pOldTop;
			return tempVal;
		}
		else
		{
			return -1;
		}
	}
	int Size() const
	{
		if( !Empty() )
		{
			return pTop->CountElements();
		}
		else
		{
			return 0;
		}
	}
	bool Empty() const
	{
		return pTop == nullptr;
	}
	Iterator begin()
	{
		return{ pTop };
	}
	Iterator end()
	{
		return{};
	}
	ConstIterator begin() const
	{
		return{ pTop };
	}
	ConstIterator end() const
	{
		return{};
	}
private:
	Element* pTop = nullptr;
};