#include <safe_arithmetic/safe_arithmetic_int.h>
#include <limits.h> /* for minimum and maximum */
#include <stdlib.h> /* for exit */

/*
 * Returns 1 if two integers can be safely added without overflow or underflow.
 * Returns 0 otherwise.
 */
int check_add_safe_int(int a, int b) {
	// Assume safe.
	int ret = 1;

	// Check for safety here.
	if (b > 0) {
		// If b is a positive integer,
		// result of sum will be greater than value of a.
		// Check if sum will overflow.
		if (a > INT_MAX - b) {
			// If the sum is greater than maximum,
			// set return value as 0.
			ret = 0;
		}
	} else {
		// If b is a negative integer,
		// result of sum will be less than value of a.
		// Check if sum will underflow.
		if (a < INT_MIN - b) {
			// If the sum is less than minium,
			// set return value as 0.
			ret = 0;
		}
	}

	return ret;
}

/*
 * Returns sum if safe.
 * Exit with error code otherwise.
 */
int add_safe_int(int a, int b) {
	if (0 != check_add_safe_int(a, b)) {
		// If sum is safe, return sum.
		return a + b;
	} else {
		// If sum is not safe, exit.
		exit(EXIT_FAILURE);
	}
}
