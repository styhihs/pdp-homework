import java.io.IOException;
import java.util.StringTokenizer;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

public class FileSizeSortMapper extends Mapper<Object, Text, IntWritable, Text> {
	@Override
	public void map(Object key, Text value,
		Context context) throws IOException, InterruptedException {
		IntWritable out_key = new IntWritable(0);	// file size
		Text out_val = new Text();	// file name
		StringTokenizer wordList = new StringTokenizer(value.toString());
		while (wordList.hasMoreTokens()) {
			out_key.set(Integer.parseInt(wordList.nextToken()));
			out_val.set(wordList.nextToken());
			context.write(out_key, out_val);
		}
	}
}
