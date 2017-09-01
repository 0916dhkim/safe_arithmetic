# Safe Arithmetic
Static C library for safe arithmetic operations with integer types.

# Requirements
When you are building from source, this project depends on [Google Test](https://github.com/google/googletest)
which requires [CMake](https://cmake.org) v2.6.4 or newer.  
The library itself does not depend on anything.

# Build
Run following commands.  
`$ cmake .`  
`$ make`

## CMake Subdirectory
If you put this project as a CMake subdirectory, build process will produce `safe_arithmetic.a`
inside `${CMAKE_BINARY_DIR}/lib` directory.
