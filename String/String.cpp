#include "String.h"
#include <cstdlib>

DLOzTOR::String::String(){
	 data = new char;
	 capacity = 1;
	 fullness = 1;
	 data[0] = '\0';
}
DLOzTOR::String::String(const char* s) {
	capacity = std::strlen(s) + 1;
	fullness = capacity;
	data = new char[capacity];
	strcpy(data,  s);
	data[fullness - 1] = '\0';
}
char* DLOzTOR::String::To_csting() {
	char* ptr = new char[fullness];
	strcpy(ptr, data);
	ptr[fullness - 1] = '\0';
	return ptr;
}
void DLOzTOR::String::operator=(const char* str) {
	free(data);
	capacity = strlen(str) + 1;
	fullness = capacity;
	data = new char[capacity];
	strcpy(data, str);
	data[fullness - 1] = '\0';
}
//void DLOzTOR::String::Add() {

//}
namespace DLOzTOR {
	std::ostream& operator<<(std::ostream& os, DLOzTOR::String& str)
	{
		os << str.To_csting();
		return os;
	}
}
DLOzTOR::String::~String() {
	delete(data);
}