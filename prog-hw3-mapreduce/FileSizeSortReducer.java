import java.io.IOException;
import java.util.Iterator;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

public class FileSizeSortReducer extends Reducer<IntWritable, Text, IntWritable, Text> {
	@Override
	public void reduce(IntWritable key, Iterable<Text> values,
		Context context) throws IOException, InterruptedException {
		String file = "";
		Iterator<String> it = IteratorSort.Sort(values.iterator());
		while (it.hasNext()) {
			file += it.next();
			if (it.hasNext())
				file += ',';
		}
		Text filenames = new Text(file);
		context.write(key, filenames);
	}
}
