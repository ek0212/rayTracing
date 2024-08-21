cmake_minimum_required(VERSION 3.30)
project(myProject)

# Set to C++11
set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)

set (SOURCE_ONE_WEEKEND
    src/main.cpp
    src/Vec3.h
    src/Color.h
    src/Ray.h
    src/Hittable.h
    src/HittableList.h
    src/Sphere.h
)

# Executables
add_executable(rayTrace ${SOURCE_ONE_WEEKEND})