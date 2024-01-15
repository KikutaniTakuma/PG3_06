#include <iostream>
#include <algorithm>
#include <string>
#include <algorithm>
#include <mutex>

int main() {
	std::mutex mtx_;
	std::thread thread1{ [&mtx_]() {
		std::lock_guard<std::mutex> lock_{mtx_};
		std::cout << "thread1" << std::endl;
		} };

	std::thread thread2{ [&mtx_]() {
		std::lock_guard<std::mutex> lock_{mtx_};
		std::cout << "thread2" << std::endl;
		} };

	std::thread thread3{ [&mtx_]() {
		std::lock_guard<std::mutex> lock_{mtx_};
		std::cout << "thread3" << std::endl;
		} };


	thread1.join();
	thread2.join();
	thread3.join();

	return 0;
}