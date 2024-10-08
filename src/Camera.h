#pragma once

#include "Hittable.h"
#include "Vec3.h"
#include <iostream>

/**
 * @brief Represents a camera for rendering images.
 * 
 * The `Camera` class models a camera in 3D space, allowing the rendering of images by casting rays from the camera
 * through each pixel in the viewport and determining the color based on object intersections in the scene.
 */
class Camera {
public:
    double aspect_ratio = 1.0; ///< Ratio of image width over height.
    int image_width = 100; ///< Rendered image width in pixels.
    int samples_per_pixel = 10;

    /**
     * @brief Renders an image of the scene.
     * 
     * The `render` function generates an image of the scene defined by the `world` object. It iterates over each pixel
     * in the image, computes the corresponding ray, and determines the pixel color by tracing the ray through the scene.
     * The result is output in PPM format (P3) to the standard output stream.
     * 
     * @param world The scene to render, represented as an object that implements the `Hittable` interface.
     */
    void render(const Hittable& world) {
        initialize();
        std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

        for (int row = 0; row < image_height; row++) {
            std::clog << "\rScanlines remaining: " << (image_height - row) << " " << std::flush;
            for (int col = 0; col < image_width; col++) {
                Color pixel_color(0,0,0);
                for (int sample=0; sample<samples_per_pixel; sample++){
                    Ray r = get_ray(col, row);
                    pixel_color += ray_color(r,world);
                }
                write_color(std::cout, pixel_color * pixel_samples_scale);
            }
        }
        std::clog << "\rDone.                 \n";
    }

private:
    int image_height; ///< Rendered image height.
    double pixel_samples_scale;  // Color scale factor for a sum of pixel samples
    Point3 center; ///< Camera center in 3D space.
    Point3 pixel00_loc; ///< Location of the upper-left pixel.
    Vec3 pixel_delta_u; ///< Offset to the right pixel.
    Vec3 pixel_delta_v; ///< Offset to the pixel below.

    /**
     * @brief Initializes the camera parameters.
     * 
     * The `initialize` function sets up the camera by calculating the viewport dimensions, the delta vectors between pixels,
     * and the location of the upper-left pixel. It also determines the focal length and aspect ratio of the camera.
     */
    void initialize() {
        image_height = int(image_width / aspect_ratio);
        image_height = (image_height < 1) ? 1 : image_height;

        pixel_samples_scale = 1.0 / samples_per_pixel;

        center = Point3(0, 0, 0);
        auto focal_length = 1.0;
        auto viewport_height = 2.0;
        auto viewport_width = viewport_height * (double(image_width) / image_height);

        auto viewport_u = Vec3(viewport_width, 0, 0);
        auto viewport_v = Vec3(0, -viewport_height, 0);

        pixel_delta_u = viewport_u / image_width;
        pixel_delta_v = viewport_v / image_height;

        auto viewport_upper_left = center - Vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
        pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);
    }

    Ray get_ray(int i, int j) const{
        // Construct a camera ray originating from the origin and directed at randomly sampled
        // point around the pixel location i, j.
        auto offset = sample_square();
        auto pixel_sample = pixel00_loc
                            + ((i + offset.x()) * pixel_delta_u)
                            + ((j + offset.y()) * pixel_delta_v);
        auto ray_origin = center;
        auto ray_direction = pixel_sample - ray_origin;

        return Ray(ray_origin, ray_direction);
    }

    Vec3 sample_square() const{
        // Returns the vector to a random point in the [-.5,-.5]-[+.5,+.5] unit square.
        return Vec3(random_double() - 0.5, random_double() -0.5, 0);
    }

    /**
     * @brief Computes the color of a pixel given a ray.
     * 
     * The `ray_color` function calculates the color of a pixel based on the ray's interaction with the scene. If the ray hits
     * an object in the scene, the color is based on the surface normal at the hit point; otherwise, it provides a background color.
     * 
     * @param ray The ray to trace.
     * @param world The scene to render, represented as an object that implements the `Hittable` interface.
     * @return The color of the pixel.
     */
    Color ray_color(const Ray& ray, const Hittable& world) {
        HitRecord rec;
        if (world.hit(ray, Interval(0, infinity), rec)) {
            return 0.5 * (rec.normal + Color(1, 1, 1));
        }

        Vec3 unit_direction = unit_vector(ray.direction());
        auto a = 0.5 * (unit_direction.y() + 1.0);
        return (1.0 - a) * Color(1.0, 1.0, 1.0) + a * Color(0.5, 0.7, 1.0);
    }
};
