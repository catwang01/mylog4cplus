#include <iostream>

template<class T>
class Singleton
{
	public:
		static T& getInstance()
		{
			static T instance;
			return instance;
		}
	protected:
		Singleton() {};
		Singleton(const Singleton&) = delete;
		Singleton& operator=(const Singleton&) = delete;
};