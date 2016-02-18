#include <iostream>
#include <utility>
#include <thread>
#include <chrono>
#include <functional>
#include <atomic>
 

#ifdef WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

static int count = 0;
static bool stopme = false;

void f(int & count)
{
	while(!stopme)
	{
		count++;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));		
	}
}

extern "C" 
{
	std::thread t1;

	DLLEXPORT void start()
	{
		std::thread t(f,std::ref(count));
		stopme = false;
		count = 0;
		t1.swap(t);
	}

	DLLEXPORT void stop()
	{
		stopme = true;
		t1.join();
	}

	DLLEXPORT void TestSort(int a[], int length) 
	{
		std::sort(a, a+length);
	}

	DLLEXPORT int next()
	{
		return count;
	}

}