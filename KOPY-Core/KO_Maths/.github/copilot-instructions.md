# Copilot Instructions for KO_Maths

## Project Overview
KO_Maths is a header-only C++ mathematics library providing vector (vec2, vec3, vec4), matrix (mat3, mat4), quaternion (quat), and utility math functions. It is designed for easy integration into C++ projects, with a focus on performance and usability for graphics, simulation, and general math tasks.

## Key Components
- **vec2/vec3/vec4**: Float-based vector types with arithmetic, dot/cross product, normalization, swizzling, and component access. See `vec2.h`, `vec3.h`, `vec4.h`.
- **mat3/mat4**: Matrix types supporting arithmetic, determinant, transpose, inverse, and transformation matrix generation. See `mat3.h`, `mat4.h`.
- **quat**: Quaternion type for 3D rotations. See `quat.h`.
- **maths_func.h**: Utility math functions (clamp, lerp, min, max, angle conversions, trigonometry).
- **maths.h**: Main include header aggregating all types and functions.
- **enums.h**: Common enums used across types.

## Usage Patterns
- All types and functions are defined in headers; include only what you need.
- Prefer using the main `maths.h` header for most use cases.
- Construction and arithmetic are operator-overloaded for intuitive usage (e.g., `vec3 a = b + c * 2.0f;`).
- Matrix and vector multiplication follows standard math conventions (row-major, column-major as documented in headers).

## Developer Workflows
- **Builds**: No build step required for the library itself (header-only). Just include headers in your C++ project.
- **Testing**: No test suite is present by default. Add your own tests or examples as needed.
- **Debugging**: Use standard C++ debugging tools. Types are simple structs/classes with public members for easy inspection.

## Project Conventions
- All types use `float` components by default.
- Functions and operators are inlined for performance.
- No external dependencies; pure C++.
- File naming: `vecN.h/cpp`, `matN.h/cpp`, `quat.h/cpp`, `maths_func.h/cpp`.
- Keep code readable and minimal; avoid unnecessary abstractions.

## Examples
- Construct a 3D vector: `vec3 v(1.0f, 2.0f, 3.0f);`
- Normalize: `v.normalized()`
- Matrix multiplication: `mat4 m = m1 * m2;`
- Quaternion from axis/angle: `quat q = quat::fromAxisAngle(axis, angle);`

## References
- See `README.md` for a feature summary.
- See individual headers for detailed documentation and usage.

---
When generating code, follow the established patterns in the headers. If unsure, prefer minimal, readable, and idiomatic C++.
