#ifndef __VISUALIZATION_COLOR_COLORS__HPP__
#define __VISUALIZATION_COLOR_COLORS__HPP__

namespace cgzr {
// RGB values are from [0.--255.]
struct ColorRGB {
  double r;
  double g;
  double b;
  ColorRGB() : r(0.), g(0.), b(0.) {}
  ColorRGB(double new_r, double new_g, double new_b)
      : r(new_r), g(new_g), b(new_b) {}
};
}  // namespace cgzr

#endif /* __VISUALIZATION_COLOR_COLORS__HPP__ */
