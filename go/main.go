package main

import (
    "encoding/csv"
    "fmt"
    "log"
    "os"
	"strconv"
	"time"
)

func main() {
	var nums []int
	var total_time int = 0
	for i := 0; i < 10; i++ {
		nums = get_data_from_csv_file()
		start := time.Now()
		bubblesort(nums)
		duration := time.Since(start)
		time := int(duration.Milliseconds())
		total_time += time
	}

	avg_time := total_time / 10
	fmt.Println(nums[0:100])
	fmt.Println(strconv.Itoa(avg_time) + " ms")
}

func get_data_from_csv_file() []int {
	var nums []int
	filePath := "../nums.csv"
	f, err := os.Open(filePath)
    if err != nil {
        log.Fatal("Unable to read input file " + filePath, err)
    }
    defer f.Close()

    csvReader := csv.NewReader(f)
    lines, err := csvReader.ReadAll()
    if err != nil {
        log.Fatal("Unable to parse file as CSV for " + filePath, err)
    }

	for _, line := range lines {
		item, err := strconv.Atoi(line[0])
		if err != nil {
        	log.Fatal("Unable to convert a string to an int.")
    	}
		nums = append(nums, int(item))
	}

	return nums
}

func bubblesort(nums []int) {
	for i := 0; i < len(nums); i++ {
		sorted := true
		for j := 0; j < len(nums)-1; j++ {
			if nums[j] > nums[j+1] {
				key := nums[j]
				nums[j] = nums[j+1]
				nums[j+1] = key
				sorted = false
			}
		}
		if sorted == true {
			break;
		}
	}
}
