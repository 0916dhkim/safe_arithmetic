#include <safe_arithmetic/safe_arithmetic_long.h>
#include <limits.h> /* for minimum and maximum */
#include <stdlib.h> /* for exit */

int check_add_safe_long(long a, long b) {
	// Assume safe.
	int ret = 1;

	// Check for safety here.
	if (b > 0L) {
		// If b is positive,
		// result of sum will be greater than value of a.
		// Check if sum will overflow.
		if (a > LONG_MAX - b) {
			// If the sum is greater than maximum,
			// set return value as 0.
			ret = 0;
		}
	} else {
		// If b is negative,
		// result of sum will be less than value of a.
		// Check if sum will underflow.
		if (a < LONG_MIN - b) {
			// If the sum is less than minium,
			// set return value as 0.
			ret = 0;
		}
	}

	return ret;
}

long add_safe_long(long a, long b) {
	if (0 != check_add_safe_long(a, b)) {
		// If sum is safe, return sum.
		return a + b;
	} else {
		// If sum is not safe, exit.
		exit(EXIT_FAILURE);
	}
}
