#pragma once

#include "Ray.h"

/**
 * @brief Represents the record of a ray hitting a surface.
 * 
 * The `HitRecord` class contains details about the intersection of a ray with a surface, including the point of intersection,
 * the normal vector at that point, the parameter `t` along the ray, and whether the intersection is on the front face of the surface.
 */
class HitRecord {
public: 
    Point3 p;        ///< The point of intersection between the ray and the surface.
    Vec3 normal;     ///< The normal vector at the intersection point, indicating the direction perpendicular to the surface.
    double t;        ///< The parameter `t` along the ray where the intersection occurs.
    bool front_face; ///< Boolean indicating if the intersection point is on the front face of the surface.

    /**
     * @brief Sets the normal vector and front face status of the `HitRecord` based on the ray direction and outward normal.
     * 
     * @param ray The ray that intersects with the surface.
     * @param outward_normal The outward normal vector at the intersection point. This vector is assumed to be of unit length.
     */
    void set_face_normal(const Ray& ray, const Vec3& outward_normal) {
        front_face = dot(ray.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};

/**
 * @brief Abstract base class for objects that can be hit by a ray.
 * 
 * The `Hittable` class is an abstract base class for objects that can be intersected by a ray. Derived classes must implement
 * the `hit` method to provide the specific intersection logic.
 */
class Hittable {
public:
    virtual ~Hittable() = default;

    /**
     * @brief Checks if a ray intersects with the object and updates the hit record if an intersection occurs.
     * 
     * This pure virtual function must be overridden in derived classes to provide the specific intersection logic.
     * 
     * @param r The ray being tested for intersection.
     * @param ray_t The interval within which to test for intersections.
     * @param rec The hit record to be updated with intersection details if an intersection occurs.
     * 
     * @return `true` if the ray intersects with the object, `false` otherwise.
     */
    virtual bool hit(const Ray& r, Interval ray_t, HitRecord& rec) const {
        // Stub: Derived classes should implement this method.
        return false;
    }
};
