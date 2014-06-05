import java.io.IOException;
import java.util.Iterator;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Partitioner;

public class FileSizeSortPartitioner<K, V> extends Partitioner<K, V> {
	@Override
	public int getPartition(K key, V value,
		int numReduceTasks) {
		int keyNum = key.hashCode();

		if (numReduceTasks == 0) return 0;
		if (keyNum <= 450000000) return 0;
		if (keyNum > 450000000 && keyNum <= 900000000)
			return 1 % numReduceTasks;
		if (keyNum > 900000000 && keyNum <= 1350000000)
			return 2 % numReduceTasks;
		if (keyNum > 1350000000 && keyNum <= 1800000000)
			return 3 % numReduceTasks;
		return 4 % numReduceTasks;
	}
}
