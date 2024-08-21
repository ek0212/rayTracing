#pragma once

#include "Vec3.h"

/**
 * @brief Represents a ray in 3D space.
 * 
 * The `Ray` class encapsulates a ray with an origin point and a direction vector. It provides methods to access the
 * origin and direction of the ray, as well as to compute a point along the ray at a given parameter `t`.
 */
class Ray {
public:
    /**
     * @brief Default constructor that initializes a ray with default values.
     */
    Ray() {}

    /**
     * @brief Constructor that initializes the ray with a specified origin and direction.
     * 
     * @param origin The origin point of the ray.
     * @param direction The direction vector of the ray.
     */
    Ray(const Point3& origin, const Vec3& direction) : 
        _origin(origin),
        _direction(direction) {}

    /**
     * @brief Returns the origin point of the ray.
     * 
     * @return A constant reference to the origin point of the ray.
     */
    const Point3& origin() const { return _origin; }

    /**
     * @brief Returns the direction vector of the ray.
     * 
     * @return A constant reference to the direction vector of the ray.
     */
    const Vec3& direction() const { return _direction; }

    /**
     * @brief Computes the point along the ray at a given parameter `t`.
     * 
     * This method calculates the point on the ray that is `t` units away from the origin.
     * 
     * @param t The parameter indicating the position along the ray.
     * @return The point on the ray at the parameter `t`.
     */
    Point3 at(double t) const {
        return _origin + _direction * t;
    }

private:
    Point3 _origin;   ///< The origin point of the ray.
    Vec3 _direction; ///< The direction vector of the ray.
};
