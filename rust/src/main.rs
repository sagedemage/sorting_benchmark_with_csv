use std::fs;
use std::time::Instant;

fn main() {
    let mut nums: Vec<i32> = get_data_from_csv_file();

    let mut total_time = 0;

    for _i in 0..10 {
        let start = Instant::now();
        bubblesort(&mut nums);
        let time = start.elapsed();
        total_time += time.as_millis();
    }
    
    let avg_time = total_time / 10;

    println!("{:?}", &nums[0..100]);
    println!("{} ms", avg_time);

}

fn get_data_from_csv_file() -> Vec<i32> {
    let mut nums: Vec<i32> = Vec::new();
    let contents = fs::read_to_string("../nums.csv")
        .expect("Should have been able to read the file");

    for line in contents.lines() {
        let items: Vec<&str> = line.split(",").collect();
        nums.push(items[0].parse::<i32>().unwrap());
    }
    return nums;
}

fn bubblesort(nums: &mut Vec<i32>) {
    loop {
        let mut sorted: bool = true;
        for i in 0..=nums.len()-2 {
            if nums[i] > nums[i+1] {
                sorted = false;
                let key = nums[i];
                nums[i] = nums[i+1];
                nums[i+1] = key;
            }
        }
        if sorted == true {
            break;
        }
    }
}
