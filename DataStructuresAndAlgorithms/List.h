#ifndef _LIST_H_
#define _LIST_H_

template<typename Object>
class List
{
private:
	struct Node
	{
		Node(const Object& data = Object(), Node* p = nullptr, Node* n = nullptr)
			:data(data)
			, prev(p)
			, next(n)
		{}
		Object data;
		Node* prev;
		Node* next;
	};

public:
	class const_iterator
	{
		friend class List<Object>;
	public:
		const_iterator() :mCurrent(nullptr){}

		const Object& operator*(){ return retrieve(); }
		const_iterator& operator++(){
			mCurrent = mCurrent->next;
			return *this;
		}
		const_iterator operator++(int){
			auto oldIterator = *this;
			++(*this);
			return oldIterator;
		}
		const_iterator& operator--(){
			mCurrent = mCurrent->prev;
			return *this;
		}
		const_iterator operator--(int){
			auto oldIterator = *this;
			--(*this);
			return oldIterator;
		}
		bool operator==(const const_iterator& iterator) const{
			return mCurrent == iterator.mCurrent;
		}
		bool operator!=(const const_iterator& iterator) const{
			return !(*this == iterator);
		}

	protected:
		Object& retrieve() const{ return mCurrent->data; }
		const_iterator(Node* p) :mCurrent(p){}

	protected:
		Node* mCurrent;

	};
	class iterator :public const_iterator
	{
		friend class List<Object>;
	public:
		iterator(){}

		Object& operator*(){ return retrieve(); }
		const Object& operator*() const{ return const_iterator::operator *(); }
		iterator& operator++(){
			mCurrent = mCurrent->next;
			return *this;
		}
		iterator operator++(int){
			auto oldIterator = *this;
			++(*this);
			return oldIterator;
		}
		iterator& operator--(){
			mCurrent = mCurrent->prev;
			return *this;
		}
		iterator operator--(int){
			auto oldIterator = *this;
			--(*this);
			return oldIterator;
		}
	protected:
		iterator(Node*p) :const_iterator(p){}
	};

public:
	List();
	List(const List& list);
	const List& operator=(const List& list);
	~List();

	const_iterator begin() const;
	iterator begin();
	const_iterator end() const;
	iterator end();

	int size() const;
	bool empty() const;
	void clear();

	Object& front();
	const Object& front() const;
	Object& back();
	const Object& back() const;

	void push_front(const Object& object);
	void push_back(const Object& object);
	void pop_front();
	void pop_back();

	iterator insert(iterator itr, const Object& object);
	iterator erase(iterator itr);
	iterator erase(iterator start, iterator end);
	
private:
	void init();

private:
	int mSize;
	Node* mHead;
	Node* mTail;
};

template<typename Object>
typename List<Object>::iterator List<Object>::erase(iterator start, iterator end)
{
	for (auto itr = start; itr != end;)
	{
		itr = erase(itr);
	}

	return end;
}

template<typename Object>
typename List<Object>::iterator List<Object>::erase(iterator itr)
{
	Node* p = itr.mCurrent;
	iterator result(p->next);
	p->prev->next = p->next;
	p->next->prev = p->prev;
	delete p;
	--mSize;

	return result;
}

template<typename Object>
typename List<Object>::iterator List<Object>::insert(iterator itr, const Object& object)
{
	Node* p = itr.mCurrent;
	mSize++;
	return iterator(p->prev = p->prev->next = new Node(object, p->prev, p));
}

template<typename Object>
void List<Object>::pop_back()
{
	erase(--end());
}

template<typename Object>
void List<Object>::pop_front()
{
	erase(begin());
}

template<typename Object>
void List<Object>::push_back(const Object& object)
{
	insert(end(), object);
}

template<typename Object>
void List<Object>::push_front(const Object& object)
{
	insert(begin(), object);
}

template<typename Object>
const Object& List<Object>::back() const
{
	return *(--end());
}

template<typename Object>
Object& List<Object>::back()
{
	return *(--end());
}

template<typename Object>
const Object& List<Object>::front() const
{
	return *begin();
}

template<typename Object>
Object& List<Object>::front()
{
	return *begin();
}

template<typename Object>
void List<Object>::clear()
{
	while (!empty())
	{
		pop_front();
	}
}

template<typename Object>
bool List<Object>::empty() const
{
	return mSize == 0;
}

template<typename Object>
int List<Object>::size() const
{
	return mSize;
}

template<typename Object>
void List<Object>::init()
{
	mSize = 0;
	mHead = new Node;
	mTail = new Node;
	mHead->next = mTail;
	mTail->prev = mHead;
}

template<typename Object>
typename List<Object>::iterator List<Object>::end()
{
	return iterator(mTail);
}

template<typename Object>
typename List<Object>::const_iterator List<Object>::end() const
{
	return const_iterator(mTail);
}

template<typename Object>
typename List<Object>::iterator List<Object>::begin()
{
	return iterator(mHead->next);
}

template<typename Object>
typename List<Object>::const_iterator List<Object>::begin() const
{
	return const_iterator(mHead->next);
}

template<typename Object>
List<Object>::~List()
{
	clear();
	delete mHead;
	delete mTail;
}

template<typename Object>
const List<Object>& List<Object>::operator=(const List& list)
{
	if (this==&list)
	{
		return *this;
	}

	clear();

	for (auto itr = list.begin(); itr != list.end();++itr)
	{
		push_back(itr);
	}

	return *this;
}

template<typename Object>
List<Object>::List(const List& list)
{
	init();
	*this = list;
}

template<typename Object>
List<Object>::List()
{
	init();
}

#endif