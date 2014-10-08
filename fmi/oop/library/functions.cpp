#include <vector>
#include <string>
#include <cstdlib>
#include <curses.h>

int explode(std::vector<std::string> &strs, std::string str, char delimiter) {
	int lastpos = 0, count = 0;
	for(int i=0;i<str.length();i++) {
		if(str[i] == delimiter) count++;
	}
	int i=0;
	while(str[i]!='\0') {
		if(str[i] == delimiter || str[i+1] == '\0') {
			if(str[i+1] == '\0') strs.push_back(str.substr(lastpos, i-lastpos+1));
			else {
				strs.push_back(str.substr(lastpos, i-lastpos));
				lastpos = i+1;
			}
		}
		i++;
	}
	return count + 1;
}

std::string intToString(int num) {
	char* result = new char[16];
	sprintf(result, "%d", num);
	return std::string(result);
}

std::string doubleToString(double num) {
	char* result = new char[17];
	sprintf(result, "%.2f", num);
	return std::string(result);
}

bool isChar(int i) {
	char c = (char)i;
	if(c >= '0' && c <= '9') return true;
	if(c >= 'a' && c <= 'z') return true;
	if(c >= 'A' && c <= 'Z') return true;
	if(c == '.' || c == ',' || c == '/' || c == '\\' || c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || 
		c == '*' || c == '(' || c == ')' || c == '-' || c == '_' || c == '+' || c == '=' || c == '`' || c == '~' || c == '<' || c == '>' ||
		c == ';' || c == ':' || c == '[' || c == '{' || c == ']' || c == '}' || c == '\'' || c == '"' || c == '|' || c == '?' || c == ' ') return true;
	return false;
}

bool stringContains(std::string key, std::string str) {
	size_t position = str.find(key);
	if(position != std::string::npos) return true;
	return false;
}

std::vector<std::string> split(std::string str) {
	std::vector<std::string> lines;
	int maxX, maxY;
	getmaxyx(stdscr, maxY, maxX);
	while(str.length() > maxX) {
		lines.push_back(str.substr(0, maxX-1));
		str = str.substr(maxX-1, str.length());
	}
	lines.push_back(str.substr(0, maxX-1));
	return lines;
}