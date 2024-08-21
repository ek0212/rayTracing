#pragma once

#include "Hittable.h"
#include "Vec3.h"

/**
 * @brief Represents a sphere in 3D space that can be tested for intersections with rays.
 * 
 * The `Sphere` class inherits from the `Hittable` class and provides functionality to check if a ray intersects with the
 * sphere, as well as to record the intersection details.
 */
class Sphere : public Hittable {
public:
    /**
     * @brief Constructor that initializes the sphere with a specified center and radius.
     * 
     * The radius is clamped to a non-negative value (zero or greater).
     * 
     * @param center The center point of the sphere.
     * @param radius The radius of the sphere. It is clamped to zero or positive values.
     */
    Sphere(const Point3& center, double radius) :
        center(center),
        radius(std::fmax(0, radius)) {}

    /**
     * @brief Checks if a ray intersects with the sphere and updates the hit record if an intersection occurs.
     * 
     * This method overrides the pure virtual `hit` function from the `Hittable` class to provide specific logic for
     * sphere-ray intersection tests.
     * 
     * @param ray The ray being tested for intersection with the sphere.
     * @param interval The interval within which to test for intersections.
     * @param rec The hit record to be updated with intersection details if an intersection occurs.
     * 
     * @return `true` if the ray intersects with the sphere, `false` otherwise.
     */
    bool hit(const Ray& ray, Interval interval, HitRecord& rec) const override {
        Vec3 oc = center - ray.origin(); // Vector from ray origin to sphere center
        auto a = ray.direction().length_squared(); // Squared length of the ray direction vector
        auto h = dot(ray.direction(), oc); // Projection of oc onto ray direction
        auto c = oc.length_squared() - radius * radius; // Distance squared from ray origin to sphere surface
        auto discriminant = h * h - a * c; // Discriminant for quadratic equation

        // Check if discriminant is negative (no intersection)
        if (discriminant < 0)
            return false;

        auto sqrtd = std::sqrt(discriminant); // Square root of discriminant

        // Find the nearest root that lies in the acceptable range
        auto root = (h - sqrtd) / a;
        if (!interval.surrounds(root)) {
            root = (h + sqrtd) / a;
            if (!interval.surrounds(root))
                return false;
        }

        rec.t = root; // Record the parameter t of the intersection
        rec.p = ray.at(rec.t); // Compute the intersection point
        Vec3 outward_normal = (rec.p - center) / radius; // Compute the outward normal at the intersection point
        rec.set_face_normal(ray, outward_normal); // Set the face normal for the hit record

        return true;
    }

private:
    Point3 center; ///< The center point of the sphere.
    double radius; ///< The radius of the sphere.
};