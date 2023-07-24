# YATU (Yet Another Test Unit) - C/C++ Testing Library

YATU is a lightweight C/C++ testing library that allows you to easily create and run test units to validate the functionality of your code. With YATU, you can define test functions using a specific syntax and group them into an array to execute them collectively.

## Getting Started

To start using YATU, follow the instructions below:

1. **Include YATU Header**: Include the YATU in your CMakeLists.txt file and include the header file (`YATU.h`) in your C/C++ project.

2. **Write Test Functions**: Create test functions following the signature `void FunctionName()`. Inside these functions, use the `YASSERT()` function to check boolean conditions and verify your code's correctness.

3. **Define YTEST Struct**: Create a struct of type `YTEST` to hold the information about your test unit. This struct contains a pointer to the test function and a description string (name) for the test unit.

4. **Combine Multiple YTEST Structs**: Group multiple `YTEST` structs into an array.

5. **Run Tests**: Call the `YRUN_TESTS()` function, passing the size of the test array, the test array itself, and an optional pointer to a `FILE` (defaulted to `stdout`).

## Example

Below is an example of how to use YATU to write and execute test units:

```c
// Include the YATU header
#include "YATU.h"

// Define test functions
void TestAddition() {
    YASSERT(2 + 2 == 4);
}

void TestMultiplication() {
    YASSERT(3 * 5 == 15);
}

// Define YTEST structs for each test function
struct YTEST test_units[] = {
    { TestAddition, "Test Addition" },
    { TestMultiplication, "Test Multiplication" }
};

int main() {
    // Get the size of the test array
    int num_tests = sizeof(test_units) / sizeof(test_units[0]);

    // Run the tests and output the results to stdout
    YRUN_TESTS(num_tests, test_units, stdout);

    return 0;
}
```

## Reference

### YASSERT Function
The **YASSERT()** function is used inside the test functions to check boolean conditions. If the condition is false, the test will fail, and an error message will be displayed, indicating the failed test.

### YRUN_TEST Function
The **YRUN_TEST()** function is responsible for executing the test units. It takes the following parameters:
- **size**: the size of the **YTEST** array
- **tests**: the **YTEST** array
- **output_file** (optional): A pointer to a **FILE** where the test results will be printed. Defaulted to **stdout**.

## Integrating YATU with CMake
To integrate the YATU library with your CMake project, add this code to your CMakeLists.txt file:

```cmake
set(BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR})   #set base directory of the project
set(REPO_NAME YATU)             #set the Github repository name
set(YATU_DIR ${BASE_DIR}/YATU)  #set the base dir where the library will be downloaded
set(YATU_VERSION v1.0.0)        #set the Github library version


include(ExternalProject)        #include ExternalProject CMake library (only above version 3.0)

ExternalProject_Add(
    ${REPO_NAME}
    GIT_REPOSITORY  https://github.com/Developer310301/${REPO_NAME}.git
    GIT_TAG         ${YATU_VERSION}
    SOURCE_DIR      ${YATU_DIR}
    INSTALL_COMMAND ""
)

add_executable(${PROJECT_NAME} main.cpp) # create your executable
add_dependencies(${PROJECT_NAME} ${REPO_NAME}) # add dependencies to YATU library
target_link_directories(${PROJECT_NAME} PRIVATE ${YATU_DIR}/lib${REPO_NAME}.a)  #link the static library
target_include_directories(${PROJECT_NAME} PRIVATE ${YATU_DIR}/include) #add the YATU include directory

```
Remember to modify the file paths and other configurations in the CMakeLists.txt according to your project's structure and requirements.

## Contributing
If you find any issues with YATU or want to contribute to its development, please feel free to create a pull request or submit an issue on the GitHub repository.

## License
YATU is released under the [GNU General Public License version 3 (GNU GPLv3)](https://www.gnu.org/licenses/gpl-3.0.en.html).