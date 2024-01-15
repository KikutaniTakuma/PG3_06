#include <iostream>
#include <algorithm>
#include <string>
#include <algorithm>
#include <mutex>

int main() {
	std::mutex mtx;
	std::thread thread1{ [&mtx]() {
		std::lock_guard<std::mutex> lock{mtx};
		std::cout << "thread1" << std::endl;
		} };
	thread1.join();

	std::thread thread2{ [&mtx]() {
		std::lock_guard<std::mutex> lock_{mtx};
		std::cout << "thread2" << std::endl;
		} };
	thread2.join();

	std::thread thread3{ [&mtx]() {
		std::lock_guard<std::mutex> lock_{mtx};
		std::cout << "thread3" << std::endl;
		} };


	thread3.join();

	return 0;
}