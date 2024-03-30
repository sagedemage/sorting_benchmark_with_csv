import { open } from 'node:fs/promises';

async function main() {
	let total_time = 0
	let nums = []

	for (let i = 0; i < 10; i++) {
		nums = await Csv.getData()
		let start = performance.now()
		Sort.bubblesort(nums)
		let time = performance.now() - start
		total_time += time
	}
	
	let avg_time = Math.floor(total_time / 10)
	console.log(nums)
	console.log(avg_time + " ms")
}

class Sort {
	static bubblesort(nums) {
		for (let i = 0; i < nums.length; i++) {
			let sorted = true;
			for (let j = 0; j < nums.length; j++) {
				if (nums[j] > nums[j+1]) {
					let key = nums[j]
					nums[j] = nums[j+1]
					nums[j+1] = key
					sorted = false
				}
			}
			if (sorted === true) {
				break
			}
		}
	}
}

class Csv {
	static async getData() {
		let nums = []

		const file = await open('../nums.csv');

		for await (const line of file.readLines()) {
			let items = line.split(",")
			nums.push(parseInt(items[0]))
		}

		return nums
	}
}

main()
