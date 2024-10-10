#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
namespace DLOzTOR {
	class String
	{
	private:
		char* data;
		size_t capacity, fullness;
	public:
		String();
		String(const char* source);
		char* To_csting();
		friend std::ostream& operator<<(std::ostream& os, String& str);
		void operator = (const char* str);
		//void Add(const char*);
		~String();
	};
}

