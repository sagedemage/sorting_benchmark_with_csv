/* Bubblesort in C++ */

#include <iostream>
#include <array>
#include <fstream>
#include <list>
#include <vector>
#include <chrono>

class Sort {
	public:
		static void bubblesort(int *nums, int length) {
			for (int i = 0; i < length-1; i++) {
				bool sorted = true;
				for (int j = 0; j < length-1; j++) {
					if (nums[j] > nums[j+1]) {
						int key = nums[j];
						nums[j] = nums[j+1];
						nums[j+1] = key;
						sorted = false;
					}
				}
				if (sorted == true) {
					break;
				}
			}
		}
};

class Array {
	public:
		static std::string stringify(int *arr, int length) {
			std::string list = "[";
			for (int i = 0; i < length; i++) {
				list += std::to_string(arr[i]);

				if (i == length-1) {
					continue;
				}

				list += ",";
			}
			list += "]";
			return list;
		}
		static void convert_list_to_int_array(int *arr, std::vector<int> vec) {
			for (std::vector<int>::size_type i = 0; i < vec.size(); i++) {
				arr[i] = vec[i];
			}
		}
};

class Csv {
	public:
		static std::vector<int> getData() {
			std::string myText;
			std::ifstream readFile("../nums.csv");

			std::vector<int> myvector;

			while (getline(readFile, myText)) {
				std::string s_num = "";
				for (std::vector<int>::size_type i = 0; i < myText.length(); i++) {
					if (myText[i] == ',') {
						int num = std::stoi(s_num, 0, 10);
						myvector.push_back(num);
						s_num = "";
					} 
					else {
						s_num += myText[i];
					}
				}
			}

			readFile.close();

			return myvector;
		}
};

int main() {
	std::vector<int> vec = Csv::getData();

	int length = vec.size();

	// Convert list to int array
	int arr[length];
	Array::convert_list_to_int_array(arr, vec);

	long total_time = 0;

	for (int i = 0; i < 10; i++) {
		auto start = std::chrono::high_resolution_clock::now();
		Sort::bubblesort(arr, length);
		auto end = std::chrono::high_resolution_clock::now();

		auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		total_time += time.count();
	}

	long avg_time = total_time / 10;

	std::string stringified_array = Array::stringify(arr, 100);
	std::cout << stringified_array << std::endl;
	std::cout << std::to_string(avg_time) + " ms" << std::endl;
	return 0;
}

