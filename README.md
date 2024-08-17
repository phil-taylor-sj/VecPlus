![Alt text](https://github.com/phil-taylor-sj/images/VecPlus.png "a title")

# VecPlus

VecPlus is a lightweight library of 2-dimensional and 3-dimensional vector classes.
I created VecPlus as my own dedicated dependency for projects to avoid duplicating
the code between multiple projects.

To use the library in a CMake build, use FetchContent to retrieve the library 
directly from its GitHub repository. 

## Installing as dependency

```
include(FetchContent)
FetchContent_Declare(
  VecPlus
  GIT_REPOSITORY https://github.com/phil-taylor-sj/VecPlus.git
  GIT_TAG main
)
FetchContent_MakeAvailable(VecPlus)
```

The library can then be linked to the target executable or target library.

```
target_link_libraries(${NEW_PROJECT} VecPlus)
```

## Installing for Development

The test suite covers all tets for 

To setup the library for development & testing, first clone the repository and navigate to the build diretory. Install CMake if it is not already available, and run the CMake build system by referencing the CMakeLists.txt file in the VecPlus root directory.

```
#Clone
git clone https://github.com/phil-taylor-sj/VecPlus.git
cd VecPlus

# Install
mkdir build
cd build


# Build
cmake ../
cmake --build ./
```

Then carry out the test suite to by running the executable.

```
./VecPlus_Tests
```