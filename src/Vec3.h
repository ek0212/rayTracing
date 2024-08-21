#pragma once

#include <cmath>
#include <iostream>

/**
 * @brief Represents a 3-dimensional vector.
 * 
 * The `Vec3` class encapsulates a vector with three components: x, y, and z. It provides methods for basic vector operations,
 * including arithmetic, scaling, and length calculations.
 */
class Vec3 {
public:
    double e[3]; ///< Array to hold the components of the vector.

    /**
     * @brief Default constructor that initializes the vector to (0, 0, 0).
     */
    Vec3() : e{0, 0, 0} {}

    /**
     * @brief Constructor that initializes the vector with specified components.
     * 
     * @param e0 The x-component of the vector.
     * @param e1 The y-component of the vector.
     * @param e2 The z-component of the vector.
     */
    Vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

    /**
     * @brief Returns the x-component of the vector.
     * 
     * @return The x-component of the vector.
     */
    double x() const { return e[0]; }

    /**
     * @brief Returns the y-component of the vector.
     * 
     * @return The y-component of the vector.
     */
    double y() const { return e[1]; }

    /**
     * @brief Returns the z-component of the vector.
     * 
     * @return The z-component of the vector.
     */
    double z() const { return e[2]; }

    /**
     * @brief Unary negation operator. 
     * 
     * @return A new vector with all components negated.
     */
    Vec3 operator-() const { return Vec3(-e[0], -e[1], -e[2]); }

    /**
     * @brief Accesses the component at a given index.
     * 
     * @param i The index of the component (0 for x, 1 for y, 2 for z).
     * @return The component at index `i`.
     */
    double operator[](int i) const { return e[i]; }

    /**
     * @brief Accesses the component at a given index.
     * 
     * @param i The index of the component (0 for x, 1 for y, 2 for z).
     * @return A reference to the component at index `i`.
     */
    double& operator[](int i) { return e[i]; }

    /**
     * @brief Adds another vector to this vector.
     * 
     * @param v The vector to add.
     * @return A reference to this vector after the addition.
     */
    Vec3& operator+=(const Vec3& v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    /**
     * @brief Scales this vector by a scalar value.
     * 
     * @param t The scalar value to multiply.
     * @return A reference to this vector after scaling.
     */
    Vec3& operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    /**
     * @brief Scales this vector by the reciprocal of a scalar value.
     * 
     * @param t The scalar value to divide by.
     * @return A reference to this vector after scaling.
     */
    Vec3& operator/=(double t) {
        return *this *= 1 / t;
    }

    /**
     * @brief Computes the length (magnitude) of the vector.
     * 
     * @return The length of the vector.
     */
    double length() const {
        return std::sqrt(length_squared());
    }

    /**
     * @brief Computes the squared length of the vector.
     * 
     * @return The squared length of the vector.
     */
    double length_squared() const {
        return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
    }
};

// Type alias for `Vec3` to represent a point in 3D space.
using Point3 = Vec3;

/**
 * @brief Outputs the vector to an output stream.
 * 
 * @param out The output stream.
 * @param v The vector to output.
 * @return The output stream with the vector's components.
 */
inline std::ostream& operator<<(std::ostream& out, const Vec3& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

/**
 * @brief Adds two vectors component-wise.
 * 
 * @param u The first vector.
 * @param v The second vector.
 * @return A new vector that is the component-wise sum of `u` and `v`.
 */
inline Vec3 operator+(const Vec3& u, const Vec3& v) {
    return Vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

/**
 * @brief Subtracts the components of one vector from another.
 * 
 * @param u The vector to subtract from.
 * @param v The vector to subtract.
 * @return A new vector that is the component-wise difference of `u` and `v`.
 */
inline Vec3 operator-(const Vec3& u, const Vec3& v) {
    return Vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

/**
 * @brief Multiplies two vectors component-wise.
 * 
 * @param u The first vector.
 * @param v The second vector.
 * @return A new vector that is the component-wise product of `u` and `v`.
 */
inline Vec3 operator*(const Vec3& u, const Vec3& v) {
    return Vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

/**
 * @brief Scales a vector by a scalar value.
 * 
 * @param t The scalar value to multiply.
 * @param v The vector to scale.
 * @return A new vector that is the component-wise product of `t` and `v`.
 */
inline Vec3 operator*(double t, const Vec3& v) {
    return Vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

/**
 * @brief Scales a vector by a scalar value.
 * 
 * @param v The vector to scale.
 * @param t The scalar value to multiply.
 * @return A new vector that is the component-wise product of `v` and `t`.
 */
inline Vec3 operator*(const Vec3& v, double t) {
    return t * v;
}

/**
 * @brief Scales a vector by the reciprocal of a scalar value.
 * 
 * @param v The vector to scale.
 * @param t The scalar value to divide by.
 * @return A new vector that is the component-wise product of `v` and the reciprocal of `t`.
 */
inline Vec3 operator/(const Vec3& v, double t) {
    return (1 / t) * v;
}

/**
 * @brief Computes the dot product of two vectors.
 * 
 * @param u The first vector.
 * @param v The second vector.
 * @return The dot product of `u` and `v`.
 */
inline double dot(const Vec3& u, const Vec3& v) {
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1]
         + u.e[2] * v.e[2];
}

/**
 * @brief Computes the cross product of two vectors.
 * 
 * @param u The first vector.
 * @param v The second vector.
 * @return A new vector that is the cross product of `u` and `v`.
 */
inline Vec3 cross(const Vec3& u, const Vec3& v) {
    return Vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

/**
 * @brief Computes the unit vector of a given vector.
 * 
 * @param v The vector to normalize.
 * @return A new vector with the same direction as `v` but with a length of 1.
 */
inline Vec3 unit_vector(const Vec3& v) {
    return v / v.length();
}