# KO_Maths

A C++ mathematics library by Kieran, providing vector and matrix types and operations, as well as miscellaneous mathematical functions.

## Features

### Vector Types

- **vec2**: 2D vector with float components.
- **vec3**: 3D vector with float components.
- **vec4**: 4D vector with float components.

**Functionality:**
- Construction from components or other vectors.
- Arithmetic operations: addition, subtraction, multiplication, division (with scalars and other vectors).
- Dot product, cross product (for vec3), normalization, length, distance.
- Swizzling and component access.

### Matrix Types

- **mat3**: 3x3 matrix of floats.
- **mat4**: 4x4 matrix of floats.

**Functionality:**
- Construction from components or vectors.
- Arithmetic operations: addition, subtraction, multiplication (with scalars, vectors, and matrices).
- Determinant, transpose, inverse.
- Matrix-vector and matrix-matrix multiplication.
- Common transformation matrices (rotation, translation, scaling).

### Miscellaneous Functions

- Utility math functions (e.g., clamp, lerp, min, max).
- Angle conversions (degrees/radians).
- Trigonometric helpers.
- Possibly random number utilities.

---

This library is header-only and designed for easy integration into C++ projects. See the header files for detailed documentation and usage examples.
