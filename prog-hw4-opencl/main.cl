__kernel void median_filter(__global int *array_in, __global int *array_out, __global int *n) {
	int idx = get_global_id(0);
	int max_idx = (*n) * (*n);
	int tmp[10] = { 0 };
	int i, j, ptr, y_st, y_ed, size, mid, min_val, min_idx;
	
	array_out[idx] = 0;
	
	y_st = -1, y_ed = 1;
	if (idx % *n == 0) {
		y_st = 0;
	} else if (idx % *n == *n - 1) {
		y_ed = 0;
	}

	size = 0;
	for (i = -1; i <= 1; i++) {
		for (j = y_st; j <= y_ed; j++) {
			ptr = idx + (i * (*n)) + j;
			if (ptr < 0) {
				continue;
			} else if (ptr >= max_idx) {
				break;
			}
			tmp[size++] = array_in[ptr];
		}
	}

	mid = size / 2;	// median position
	for (i = 0; i <= mid; i++) {
		min_idx = i;
		min_val = tmp[i];
		for (j = i + 1; j < size; j++) {
			if (tmp[j] < min_val) {
				min_idx = j;
				min_val = tmp[j];
			}
		}
		
		ptr = tmp[i];
		tmp[i] = tmp[min_idx];
		tmp[min_idx] = ptr;
	}

	array_out[idx] = tmp[mid];
}
