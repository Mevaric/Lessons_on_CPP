// PatternSingleton.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//class Singleton
//{
//private:
//	Singleton() {}
//	Singleton(const Singleton&);
//	Singleton& operator=(Singleton&);
//public:
//	static Singleton& getInstance() {
//		static Singleton instance;
//		return instance;
//	}
//	int a;
//};
//
//int main()
//{
//	Singleton * s = new Singleton();
//	s->getInstance();
//	s->a = 10;
//	Singleton * s2 = new Singleton;
//    return 0;
//}
//
class Singleton
{
public:
	Singleton();
	~Singleton();
	static Singleton* getInstance();
private:
	static Singleton* _instance;
};

Singleton::Singleton()
{
}

Singleton::~Singleton()
{
}
Singleton* Singleton::_instance = 0;
Singleton* Singleton::getInstance() {
	if (_instance == 0) {
		_instance = new Singleton;
	}
	return _instance;
}