#ifndef DEQUE_H_DEFINED
#define DEQUE_H_DEFINED

#include <assert.h>

template <typename T>
struct node{
	T data;
	node<T>* previous;
	node<T>* next;
};

template <typename T>
class deque{
private:
	node<T>* _front;
	node<T>* _back;
	int _size;
public:
	deque()
	{
		_front = NULL;
		_back = NULL;
		_size = 0;
	}
	deque(const deque& other)
	{
		_front = NULL;
		_back = NULL;
		_size = 0;
		*this = other;
	}
	deque<T>& operator=(const deque<T>& other)
	{
		if(&other != this) {
			cleanup();
			node<T>* it = other._front;
			int i = 0;
			while(it!=other._back)
			{
				push_back(it->data);
				it = it->next;
			}
			push_back(it->data);
		}
		return *this;
	}
	~deque()
	{
		cleanup();
	}
	void cleanup()
	{
		while(_front!=_back)
		{
			pop_back();
		}
		pop_back();
	}
	int size() const
	{
		return _size;
	}
	void push_back(T data)
	{
		node<T>* temp = new node<T>;
		temp->data = data;
		temp->previous = NULL;
		temp->next = NULL;
		if(empty()) {
			_front = temp;
			_back = temp;
		}
		else {
			temp->previous = _back;
			_back->next = temp;
			_back = temp;
		}
		_size++;
	}
	void pop_back()
	{
		if(!empty()) {
			node<T>* temp = _back;
			_back = _back->previous;
			if(_back != NULL) _back->next = NULL;
			delete temp;
			_size--;
		}
	}
	void push_front(T data)
	{
		node<T>* temp = new node<T>;
		temp->data = data;
		temp->previous = NULL;
		temp->next = NULL;
		if(empty()) {
			_front = temp;
			_back = temp;
		}
		else {
			temp->next = _front;
			_front->previous = temp;
			_front = temp;
		}
		_size++;
	}
	void pop_front()
	{
		if(!empty()) {
			node<T>* temp = _front;
			_front = _front->next;
			delete temp;
			_size--;
		}
	}
	void removeAt(const int index)
	{
		assert(index<_size);
		assert(index>=0);
		if(index == 0) 
		{
			pop_front();
			return;
		}
		if(index == _size-1) 
		{
			pop_back();
			return;
		}
		node<T>* it = _front;
		for(int i=0;i<index;i++)
		{
			it = it->next;
		}
		node<T>* save = it;
		it->previous->next = it->next;
		it->next->previous = it->previous;
		delete save;
		_size--;
	}
	bool empty()
	{
		return _size == 0;
	}
	T& front() const
	{
		return _front->data;
	}
	T& back() const
	{
		return _back->data;
	}
	T& operator[] (const int n) {
		node<T>* it = _front;
		for(int i = 0;i < n; i++) {
			it = it->next;
		}
		return it->data;
	}
};

#endif