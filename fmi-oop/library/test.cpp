#include "Library.h"

int main() {
	Library *test = new Library();
	test->startConsole();
	delete test;
	return 0;
}