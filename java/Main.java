import java.util.*;
import java.io.*;

class Main {
	public static void main(String[] args) {
		long total_time = 0;
		Integer[] arr = new Integer[0];

		for (int i = 0; i < 10; i++) {
			Stack<Integer> stack = Csv.getData();
			
			arr = stack.toArray(new Integer[stack.size()]);

			long start = System.currentTimeMillis();

			Sort.bubblesort(arr);

			long time = System.currentTimeMillis() - start;

			total_time += time;
		}

		long avg_time = total_time / 10;

		System.out.println(Arrays.toString(Arrays.copyOfRange(arr, 0, 100)));
		System.out.println(avg_time + " ms");
	}
}

class Sort {
	public static void bubblesort(Integer[] arr) {
		for (int i = 0; i < arr.length; i++) {
			boolean sorted = true;
			for (int j = 0; j < arr.length-1; j++) {
				if (arr[j] > arr[j+1]) {
					Integer key = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = key;
					sorted = false;
				}
			}

			if (sorted == true) {
				break;
			}
		}
	}
}

class Csv {
	public static Stack<Integer> getData() {
		Stack<Integer> stack = new Stack<Integer>();
		try {
			BufferedReader br = new BufferedReader(new FileReader("../nums.csv"));
			String line;
			while ((line = br.readLine()) != null) {
				String[] values = line.split(",");
				stack.push(Integer.parseInt(values[0]));
			}

		} catch(IOException e) {
		
		}
		return stack;
	}
}
