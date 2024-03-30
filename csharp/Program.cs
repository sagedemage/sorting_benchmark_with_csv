// See https://aka.ms/new-console-template for more information
using System.IO;
using System.Diagnostics;

class Program {
	static void Main(string[] args) {
		long total_time = 0;
		int[] arr = {};
		for (int i = 0; i < 10; i++) {
			arr = Csv.getData();
			Stopwatch watch = Stopwatch.StartNew();
			Sort.bubblesort(arr);
			watch.Stop();
			long time = watch.ElapsedMilliseconds;
			total_time += time;
		}
		long avg_time = total_time / 10;
		Console.WriteLine(string.Join(",", new ArraySegment<int>(arr, 0, 100)));
		Console.WriteLine(avg_time + " ms");
	}
}

class Sort {
	public static void bubblesort(int[] arr) {
		for (int i = 0; i < arr.Length; i++) {
			bool sorted = true;
			for (int j = 0; j < arr.Length-1; j++) {
				if (arr[j] > arr[j+1]) {
					int key = arr[j];
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
	public static int[] getData() {
		List<int> arr = new List<int>();
		using(var reader = new StreamReader("../nums.csv")) {
			while (!reader.EndOfStream) {
				var line = reader.ReadLine();
				var values = line!.Split(','); // issue here

				arr.Add(Int32.Parse(values[0]));
			}
		}
		return arr.ToArray();
	}
}
