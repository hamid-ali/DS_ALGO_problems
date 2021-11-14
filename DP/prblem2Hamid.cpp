#include <bits/stdc++.h>
using namespace std;

void row_col_sum(vector<vector<int> > &arr, vector<int> &sum)
{
	int m = arr.size(), n = arr[0].size(), i = 0, j = 0,s = 0;

	// finding the row sum
	for (i = 0; i < m; ++i) {
		s = 0;
		for (j = 0; j < n; ++j) {
			s = s + arr[i][j];
		}
        sum.push_back(s);
	}

	// finding the column sum
    for (i = 0; i < n; ++i) {
		s = 0;
		for (j = 0; j < m; ++j) {
			s = s + arr[i][j];
		}
        sum.push_back(s);
	}
}

// function to find first index >= x
int lowerIndex(vector<int> &sum, int x)
{
	int l = 0, h = sum.size() - 1;
	while (l <= h) {
		int mid = (l + h) / 2;
		if (sum[mid] >= x )
			h = mid - 1;
		else
			l = mid + 1;
	}
	return l;
}





//function to find last index <= y
int upperIndex(vector<int> &sum, int y)
{
	int l = 0, h = arr.size() - 1;
	while (l <= h) {
		int mid = (l + h) / 2;
		if (sum[mid] <= y)
			l = mid + 1;
		else
			h = mid - 1;
	}
	return h;
}



// function to count elements within given range
int countInRange(vector<int> &arr, int x, int y)
{
	int count = 0;
	count = upperIndex(arr, y) - lowerIndex(arr, x) + 1;
	return count;
}

// driver function
int main()
{
	vector<vector<int> > arr = {     
                                {1, 2, 3},  
                                {4, 5, 6},  
                                {7, 8, 9}  
                            };
    vector<int> sum;

	// Preprocess array
    row_col_sum(arr, sum);
	sort(sum.begin(), sum.end());

	// Answer queries
	int l = 1, r = 4;
	cout << countInRange(sum, l, r) << endl;

	l = 6, r = 25;
	cout << countInRange(sum, l, r) << endl;
	return 0;
}
