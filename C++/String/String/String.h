#pragma once
#include <iostream>

class String
{
private:
	char *s;
	int length;
public:
	void PrintStr() const; //этот метод не изменяет строку
	const char *Find(const char *substr) const;


	//classwork
	void UpReg();
	bool FirstNChar(int n, String &result); 
	bool EndNChar(int n, String &result); 
	bool Substr(int n, int position, String &result);
	void DeleteSpace();

	const char *c_str() const{//доступ для чтения, inline-метод
		return s;
	} 
	
	//перегрузка оператора присваивания
	void operator=(const String &source);
	String operator+=(const String &source);
	//inline
	String operator+(const String &source) const{
		String res(*this);
		std::cout << "1"<<s<<std::endl;
		res += source;
		return res ;
	}



	//ctor
	String();
	String(const char *p);
	String(char c, size_t n);
	String(const String &orig); //конструктор копирования
	~String();
	String(String&& temporary) :s(nullptr), length(0)
	{
		
		s = temporary.s;
		length = temporary.length;			
		temporary.s= NULL;
		temporary.length = 0;
		std::cout << "move" << s << std::endl;
		
	}

	
};

void PrintStr(String str);



inline int sqr(int x){
	return x*x;
}