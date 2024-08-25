#pragma once

/**
 * @brief Represents a closed interval on the real number line.
 * 
 * The `Interval` class encapsulates a range defined by a minimum and maximum value. It provides methods to query
 * the size of the interval, check if a value is within the interval, and check if a value is strictly within the interval.
 */
class Interval {
public:
    double min; ///< The minimum value of the interval.
    double max; ///< The maximum value of the interval.

    /**
     * @brief Default constructor that creates an empty interval.
     * 
     * The default interval is set to an empty range with `min` as positive infinity and `max` as negative infinity.
     */
    Interval() : min(+infinity), max(-infinity) {}

    /**
     * @brief Constructor that initializes the interval with the given minimum and maximum values.
     * 
     * @param min The minimum value of the interval.
     * @param max The maximum value of the interval.
     */
    Interval(double min, double max) : min(min), max(max) {}

    /**
     * @brief Computes the size (length) of the interval.
     * 
     * @return The difference between the maximum and minimum values of the interval.
     */
    double size() const {
        return max - min;
    }

    /**
     * @brief Checks if a value is within the interval, inclusive.
     * 
     * @param x The value to check.
     * @return `true` if the value is within the interval, inclusive; `false` otherwise.
     */
    bool contains(double x) const {
        return min <= x && x <= max;
    }

    /**
     * @brief Checks if a value is strictly within the interval, exclusive.
     * 
     * @param x The value to check.
     * @return `true` if the value is strictly within the interval; `false` otherwise.
     */
    bool surrounds(double x) const {
        return min < x && x < max;
    }

    double clamp(double x) const {
        if (x < min) return min;
        if (x > max) return max;
        return x;
    }

    static const Interval empty;   ///< Represents an empty interval (no values).
    static const Interval universe; ///< Represents a universal interval (all possible values).
};

// Definitions of static members
const Interval Interval::empty = Interval(+infinity, -infinity);
const Interval Interval::universe = Interval(-infinity, +infinity);
