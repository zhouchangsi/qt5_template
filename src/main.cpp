#include "mainwindow.h"

#include <QApplication>

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  
  return a.exec();
}

// create a camera
// origin = (0, 0, 0)
// lower_left_corner = (-2, -1, -1)
// horizontal = (4, 0, 0)
// vertical = (0, 2, 0)
// ray origin = camera origin
// ray direction = lower_left_corner + u * horizontal + v * vertical

// get hit point and the normal of the surface
// reflect's origin = hit point
// reflect's direction is determined by the material
// diffuse: random direction

/**
 * function random_0_to_1()
 */

 /**
  * @brief length_of_vector(vector)
  * 
  */

/**
 * function random_in_unit_sphere() {

 }
 */
void random_in_unit_sphere() {
  // random a point in unit sphere
    // let a,b,c = get_(3)_variables_by_(random_0_to_1)
  // a = random_a_number_between_0_and_1
  // b = random_a_number_between_0_and_1
  // c = random_a_number_between_0_and_1
  // vector = (a, b, c)
  // if vector.length() > 1, random again
  // return normalize(vector)
}
// metal: reflected direction
// reflect_ray = ray - 2 * dot(ray, normal) * normal

// dielectric surface has two directions, one is reflected, one is refracted
// refractive_index = 0.4
// refracted direction is determined by Snell's law
// n1 * sin(theta1) = n2 * sin(theta2)
// theta1 is the angle between ray and normal
// theta2 is the angle between refracted ray and normal
// n1 is the refractive index of the medium where the ray comes from
// n2 is the refractive index of the medium where the ray goes to
// n1 and n2 are both positive
// if n1 > n2, there is a critical angle

// break the recursion if hit
// 1. light
// 2. darkness
// 3. sky box
// 4. recursion depth over limit

// how to calculate hit point, for now we only consider sphere
// calculate by ray, sphere center and radius
// t_min: the minimum distance of the ray to hit point
// t_max: the maximum distance of the ray to hit point
// normal = normalize(hit_point - sphere_center)