#include <iostream>
#include <cstring>
#include <cassert>
#include "string.h"

String::String()
{
	first = NULL;
	last = NULL;
}

String::String(const char* str)
{
	first = NULL;
	last = NULL;
	for(int i=0;i<strlen(str);i++)
	{
		push(str[i]);
	}
}

String::String(const String& other)
{
	first = NULL;
	last = NULL;
	*this = other;
}

String::~String()
{
	clear();
}

String& String::operator=(const char* str)
{
	clear();
	for(int i=0;i<strlen(str);i++)
	{
		push(str[i]);
	}
	return *this;
}

String& String::operator=(const String& other)
{
	if(&other != this)
	{
		clear();
		node* it = other.first;
		while(it!=NULL)
		{
			push(it->data);
			it = it->link;
		}
	}
	return *this;
}

String operator+(const String& str1, const String& str2)
{
	String concatStr = str1;
	node* it = str2.first;
	while(it!=NULL)
	{
		concatStr.push(it->data);
		it = it->link;
	}
	return concatStr;
}

String operator+(const String& str1, const char* str2)
{
	String concatStr = str1;
	for(int i=0;i<strlen(str2);i++)
	{
		concatStr.push(str2[i]);
	}
	return concatStr;
}

String operator+(const char* str1, const String& str2)
{
	String concatStr = str1;
	node* it = str2.first;
	while(it!=NULL)
	{
		concatStr.push(it->data);
		it=it->link;
	}
	return concatStr;
}

String operator+(const String& str1, const char c)
{
	String concatStr = str1;
	concatStr.push(c);
	return concatStr;
}

String operator+(const char c, const String& str2)
{
	String concatStr;
	concatStr.push(c);
	node* it = str2.first;
	while(it!=NULL)
	{
		concatStr.push(it->data);
		it=it->link;
	}
	return concatStr;
}

String& String::operator+=(const char c)
{
	push(c);
	return *this;
}

String& String::operator+=(const char* other)
{
	for(int i=0;i<strlen(other);i++)
	{
		push(other[i]);
	}
	return *this;
}

String& String::operator+=(const String& other)
{
	node* it = other.first;
	while(it!=NULL)
	{
		push(it->data);
		it = it->link;
	}
	return *this;
}

String operator*(const String& str, const int n)
{
	String concatStr;
	for(int i=0;i<n;i++)
	{
		node* it = str.first;
		while(it!=NULL)
		{
			concatStr.push(it->data);
			it = it->link;
		}
	}
	return concatStr;
}

String& String::operator*=(const int n)
{
	String temp = *this;
	for(int i=0;i<n-1;i++)
	{
		*this+=temp;
	}
	return *this;
}

bool String::operator==(const String& other)
{
	if(length() != other.length()) return false;
	node* it = first;
	node* otherIt = other.first;
	while(it!=NULL)
	{
		if(it->data != otherIt->data) return false;
		it = it->link;
		otherIt = otherIt->link;
	}
	return true;
}

bool String::operator!=(const String& other)
{
	return !(*this==other);
}

char& String::operator[](const int n)
{
	assert(n >= 0);
	assert(n < length());
	node* it = first;
	int i = 0;
	while(it!=NULL && i < n)
	{
		i++;
		it = it->link;
	}
	return it->data;
}

int String::operator[](const char c)
{
	node* it = first;
	int i = 0;
	while(it!=NULL)
	{
		if(it->data == c) return i;
		i++;
		it = it->link;
	}
	return -1;
}

int String::operator[](const char* str)
{
	node* it = first;
	int i = 0;
	while(it!=NULL)
	{
		if(it->data == str[0])
		{
			it = it->link;
			int j = 1;
			while(j < strlen(str) && it != NULL && it->data == str[j])
			{
				j++;
				it = it->link;
			}
			if(j == strlen(str)) return i;
			if(it == NULL) return -1;
			i += j;
		}
		i++;
		it = it->link;
	}
	return -1;
}

int String::operator()()
{
	return length();
}

String String::operator()(const int n)
{
	String str = *this;
	return str(n, length()-1);
}

String String::operator()(const int n, const int m)
{
	assert(n < m);
	String substr;
	node* it = first;
	int i = 0;
	while(it!=NULL && i <= m)
	{
		if(i >= n) substr.push(it->data);
		i++;
		it = it->link;
	}
	return substr;
}

std::ostream& operator<<(std::ostream& out, String ob)
{
	node* it = ob.first;
	while(it!=NULL)
	{
		out<<it->data;
		it=it->link;
	}
	return out;
}

std::istream& operator>>(std::istream& in, String& ob)
{
	ob.clear();
	char c = in.get();
	while(c!='\n' && c!=' ')
	{
		ob.push(c);
		c = in.get();
	}
	return in;
}

bool String::operator<(const String& other)
{
	node* it = first;
	node* otherIt = other.first;
	while(it != NULL && otherIt != NULL)
	{
		if(it->data > otherIt->data) return false;
		else if(it->data < otherIt->data) return true;
		it = it->link;
		otherIt = otherIt->link;
	}
	if(it == NULL && otherIt != NULL) return true;
	return false;
}

bool String::operator>(const String& other)
{
	return !(*this<other) && *this != other;
}

bool String::operator>=(const String& other)
{
	return !(*this<other);
}

bool String::operator<=(const String& other)
{
	return *this<other || *this == other;
}

void String::push(char c)
{
	node* newNode = new node;
	newNode->data = c;
	newNode->link = NULL;
	if(isEmpty())
	{
		first = newNode;
		last = newNode;
	}
	else
	{
		last->link = newNode;
		last = newNode;
	}
}

bool String::isEmpty()
{
	return first==NULL;
}

void String::clear()
{
	node* it = first;
	while(it!=NULL)
	{
		first = first->link;
		delete it;
		it = first;
	}
	first = NULL;
	last = NULL;
}

int String::length() const
{
	int _length = 0;
	node* it = first;
	while(it!=NULL)
	{
		_length++;
		it = it->link;
	}
	return _length;
}