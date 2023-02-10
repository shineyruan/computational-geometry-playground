#ifndef SRC_VISUALIZATION_DRAWABLE_DRAWABLE_TYPE_HPP_
#define SRC_VISUALIZATION_DRAWABLE_DRAWABLE_TYPE_HPP_

#include <string>

namespace cgzr {
enum class DrawableType { POINT_SET = 0, LINE_STRING, UNSUPPORTED };

inline std::string ToString(DrawableType type) {
  std::string ret;

  switch (type) {
    case DrawableType::POINT_SET:
      ret = "point set";
      break;

    case DrawableType::LINE_STRING:
      ret = "line string";
      break;

    case DrawableType::UNSUPPORTED:
      ret = "unsupported";
      break;

    default:
      ret = "unknown";
      break;
  }

  return ret;
}
}  // namespace cgzr

#endif  // SRC_VISUALIZATION_DRAWABLE_DRAWABLE_TYPE_HPP_
