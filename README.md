<img src="https://raw.githubusercontent.com/phil-taylor-sj/images/main/vecplus-logo.png" alt="Logo" width="400"/>

# VecPlus

VecPlus is a lightweight library of template classes designed to handle 2D and 3D vectors or points in Cartesian coordinates.

## Features

| Class | Description |
| --- | --- |
| `Vec2i` | A vector/point class containing integer type (x, y) components. |
| `Vec2f` | A vector/point class containing float type (x, y) components. |
| `Vec2d` | A vector/point class containing double type (x, y) components. |
| `Vec3i` | A vector/point class containing integer type (x, y, z) components. |
| `Vec3f` | A vector/point class containing float type (x, y, z) components. |
| `Vec3d` | A vector/point class containing double type (x, y, z) components. |

| Method | Description | Owner Classes |
| --- | --- | --- |
| `mag()` | Calculate the magnitude of the current vector.  | Vec2f, Vec2d, Vec3f, Vec3d |
| `mag(Vec...)` | Calculate the magnitude of vector obtained by subtracting the vector argument from the current vector. OR. Calculate the distance between two points. | Vec2f, Vec2d, Vec3f, Vec3d |
| `rotate(Scalar)` | Rotate the current vector by the given angle (in degrees).  | Vec2f, Vec2d, Vec3f, Vec3d |
| `rotate(Char, Scalar)` | Rotate the current vector around the specified axis (indicated by a character) by the given angle (in degrees). | Vec2f, Vec2d, Vec3f, Vec3d |
| `dot(Scalar)` | Calculate the dot product of the current vector and a vector of values all equal to the scalar argument (int, float, double).  | Vec2f, Vec2d, Vec3f, Vec3d |
| `dot(Vec...)` | Calculate the dot product of the current vector and the vector argument. | Vec2f, Vec2d, Vec3f, Vec3d |
| `toFloat()` | Convert the current vector to a vector of float type components. Return a new vector. | Vec2i, Vec3i |
| `toDouble()` | Convert the current vector to a vector of double type components. Return a new vector. | Vec2i, Vec3i |

| Operator | Owner Classes |
| --- | --- |
| `+ ` | All | 
| `+=` | All | 
| `-` | All | 
| `-=` | All |
| `*` | All |
| `*=` | All |
| `/` | Vec2f, Vec2d, Vec3f, Vec3d |
| `/=` | Vec2f, Vec2d, Vec3f, Vec3d |

## Usage 

```cpp
Vec2<float> a(3.5f, -4.2f);
Vec2<float> b(1.5f, 2.8f);

// Unary functions
auto absA = a.abs();    // Returns (3.5, 4.2)
float maxA = a.max();     // Returns 3.5
float minA = a.min();     // Returns -4.2

// Binary arithmetic operations
auto sum    = a + b;     // Component-wise addition: (5.0, -1.4)
auto diff   = a - b;     // Component-wise subtraction: (2.0, -7.0)
auto scaled = a * 2.0f;  // Scalar multiplication: (7.0, -8.4)
auto compMul = a * b;    // Component-wise multiplication: (5.25, -11.76)

// Compound assignment operations
a += b;   // a becomes (5.0, -1.4)
a -= b;   // a reverts to (3.5, -4.2)
a *= 2.0f;  // a becomes (7.0, -8.4)
a *= b;   // a becomes (10.5, -23.52)

// Equality check
bool equal = (a == a);  // Returns true
```
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
