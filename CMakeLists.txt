cmake_minimum_required(VERSION 3.0)
project(Blatt1)

# just lists the sources that we need to build our lib
# note that "main" is exluded here
set(FIELDLIB_SOURCES
  src/blas.c
  src/blas.h
  src/fields.c
  src/fields.h
  src/real.h
 # src/vectorFieldCreator.c
)




# adds a library target called nastlib to be built from the source files
add_library(fieldlib ${FIELDLIB_SOURCES})
# Specifies the include directory to use when compiling our target nastlib.
target_include_directories(fieldlib PUBLIC src)

# MSVC is set to true when the compiler is some version of Microsoft Visual C++ or another compiler simulating Visual C++.
# Many mathematical functions (pow, sqrt, fabs, log etc.) are declared in math.h and require the library libm to be linked.
# Unlike libc, which is automatically linked, libm is a separate library and often requires explicit linkage.
# The linker presumes all libraries to begin with lib, so to link to libm you link to m.
# This is probably not required for Windows which is why we use the "if (NOT MSVC)" here
if (NOT MSVC)
  target_link_libraries(fieldlib m)
endif(NOT MSVC)

# Catch Bugs Before Testing
# Compiler warnings are often indicators of future bugs
# that you would otherwise see only at runtime.
if(MSVC)
  target_compile_options(fieldlib PRIVATE /W4 /WX)
else(MSVC)
  target_compile_options(fieldlib PRIVATE -Wall -Wextra -pedantic -Werror)
endif(MSVC)

# Adds an executable target called nast to be built from the source/main.c
add_executable(blatt1 src/blatt1.c)
# links our executable with the source library nastlib
target_link_libraries(blatt1 fieldlib)
# Add a subdirectory to the build (where another CMakeLists.txt is located)
add_subdirectory(tests)

