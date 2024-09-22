<img src="https://raw.githubusercontent.com/phil-taylor-sj/images/main/vecplus-logo.png" alt="Logo" width="400"/>

# VecPlus

VecPlus is a lightweight library of template classes designed to handle 2D and 3D vectors or points in Cartesian coordinates.

## Features

| Class | Description |
| --- | --- |
| Vec2i | A vector/point class containing integer type (x, y) components. |
| Vec2f | A vector/point class containing float type (x, y) components. |
| Vec2d | A vector/point class containing double type (x, y) components. |
| Vec3i | A vector/point class containing integer type (x, y, z) components. |
| Vec3f | A vector/point class containing float type (x, y, z) components. |
| Vec3d | A vector/point class containing double type (x, y, z) components. |

| Method | Description | Owner Classes |
| --- | --- | --- |
| `mag()` | Calculate the magnitude of the current vector.  | Vec2f, Vec2d, Vec3f, Vec3d |
| `mag(Vec...)` | Calculate the magnitude of vector obtained by subtracting the vector argument from the current vector. OR. Calculate the distance between two points. | Vec2f, Vec2d, Vec3f, Vec3d |
| `dot(Scalar)` | Calculate the dot product of the current vector and a vector of values all equal to the scalar argument (int, float, double).  | Vec2f, Vec2d, Vec3f, Vec3d |
| `dot(Vec...)` | Calculate the dot product of the current vector and the vector argument. | Vec2f, Vec2d, Vec3f, Vec3d |
| `toFloat()` | Convert the current vector to a vector of float type components. Return a new vector. | Vec2i, Vec3i |
| `toDouble()` | Convert the current vector to a vector of double type components. Return a new vector. | Vec2i, Vec3i |



## Installing as Dependency

To use the library in a CMake build, use FetchContent to retrieve the library 
directly from its GitHub repository. 

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
