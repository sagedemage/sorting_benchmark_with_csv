"""Benchmark bubble sort"""
from typing import List
import time
import math
import csv
from functools import partial

class Sort:
    @staticmethod
    def bubblesort(arr: List[int]) -> List[int]:
        """Sort a list using bubblesort"""
        for _ in range(len(arr)):
            is_sorted = True
            for j in range(len(arr)-1):
                if arr[j] > arr[j+1]:
                    key = arr[j]
                    arr[j] = arr[j+1]
                    arr[j+1] = key
                    is_sorted = False
            if is_sorted is True:
                break
        return arr

class Csv:
    @staticmethod
    def get_data() -> List[int]:
        """Get data from csv file"""
        open_utf8 = partial(open, encoding='UTF-8')
        file = open_utf8('../nums.csv', 'r')
        reader = csv.reader(file)
        rows = []
        for row in reader:
            rows.append(int(row[0]))

        return rows



def main():
    nums = []
    total_time = 0

    for _ in range(10):
        nums = Csv.get_data()

        start = time.time()

        Sort.bubblesort(nums)

        t_time = (time.time() - start) * math.pow(10, 3)
        total_time += t_time

    avg_time = math.floor(total_time / 10)
    print(nums[0:100])
    print(str(avg_time) + " ms")

if __name__ == "__main__":
    main()
