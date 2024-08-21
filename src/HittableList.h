#pragma once

#include "Hittable.h"

#include <memory>
#include <vector>

using std::make_shared;
using std::shared_ptr;

/**
 * @brief Represents a list of hittable objects that can be tested for intersections by a ray.
 * 
 * The `HittableList` class manages a collection of `Hittable` objects and provides functionality to check for intersections
 * with all objects in the list.
 */
class HittableList : public Hittable {
public:
    std::vector<shared_ptr<Hittable>> objects; ///< List of objects that can be tested for intersections.

    /**
     * @brief Default constructor that creates an empty `HittableList`.
     */
    HittableList() {}

    /**
     * @brief Constructor that initializes the `HittableList` with a single `Hittable` object.
     * 
     * @param object A shared pointer to a `Hittable` object to add to the list.
     */
    HittableList(shared_ptr<Hittable> object) { add(object); }

    /**
     * @brief Clears all objects from the list.
     */
    void clear() { objects.clear(); }
    
    /**
     * @brief Adds a `Hittable` object to the list.
     * 
     * @param object A shared pointer to the `Hittable` object to add.
     */
    void add(shared_ptr<Hittable> object) {
        objects.push_back(object);
    }

    /**
     * @brief Checks if a ray intersects with any object in the list and updates the hit record if an intersection occurs.
     * 
     * This method overrides the pure virtual `hit` function from the `Hittable` class.
     * 
     * @param ray The ray being tested for intersection.
     * @param interval The interval within which to test for intersections.
     * @param rec The hit record to be updated with intersection details if an intersection occurs.
     * 
     * @return `true` if the ray intersects with any object in the list, `false` otherwise.
     */
    bool hit(const Ray& ray, Interval interval, HitRecord& rec) const override {
        // Stub: Implementation of hit logic for checking intersections with all objects in the list.
        return false;
    }
};
