#pragma once

struct node
{
	char data;
	node* link;
};

class String
{
private:
	node* first;
	node* last;
public:
	String();
	String(const char*);
	String(const String&);
	~String();
	String& operator=(const char*);
	String& operator=(const String&);
	friend String operator+(const String&, const String&);
	friend String operator+(const String&, const char*);
	friend String operator+(const char*, const String&);
	friend String operator+(const String&, const char);
	friend String operator+(const char, const String&);
	String& operator+=(const char);
	String& operator+=(const char*);
	String& operator+=(const String&);
	friend String operator*(const String&, const int);
	String& operator*=(const int);
	bool operator==(const String&);
	bool operator!=(const String&);
	char& operator[](const int);
	int operator[](const char);
	int operator[](const char*);
	int operator()();
	String operator()(const int);
	String operator()(const int, const int);
	friend std::ostream& operator<<(std::ostream&, String);
	friend std::istream& operator>>(std::istream&, String&);
	bool operator<(const String&);
	bool operator>(const String&);
	bool operator>=(const String&);
	bool operator<=(const String&);
	void push(char);
	bool isEmpty();
	void clear();
	int length() const;
};