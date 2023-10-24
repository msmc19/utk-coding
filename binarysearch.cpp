int binarySearch(vector <int> A, int n, int x) {

	int lowerBound = 1;
	int upperBound = n;
	int search = x;

	while(search = true) {

		if (upperBound < lowerBound) {
		
			return false;

		}

		set midPoint = lowerBound + (upperBound - lowerBound) / 2;

		if (A[midPoint] < x) {

			set lowerBound = midPoint + 1;

		}

		if (A[midPoint] < x) {

			set upperBound = midPoint - 1;

		}

		if (A[midPoint] = x) {

			exit;

		}

	}

	return false;

}
