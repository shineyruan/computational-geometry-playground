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

namespace colors {
extern const ColorRGB COLOR_BLACK;
extern const ColorRGB COLOR_WHITE;
extern const ColorRGB COLOR_RED;
extern const ColorRGB COLOR_GREEN;
extern const ColorRGB COLOR_BLUE;
extern const ColorRGB COLOR_YELLOW;
extern const ColorRGB COLOR_CYAN;
extern const ColorRGB COLOR_MAGENTA;
}  // namespace colors

}  // namespace cgzr

#endif /* __VISUALIZATION_COLOR_COLORS__HPP__ */
