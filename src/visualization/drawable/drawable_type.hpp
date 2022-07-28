#ifndef __VISUALIZATION_DRAWABLE_DRAWABLE_TYPE__HPP__
#define __VISUALIZATION_DRAWABLE_DRAWABLE_TYPE__HPP__

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

    case DrawableType::UNSUPPORTED:;
      ret = "unsupported";
      break;

    default:
      ret = "unknown";
      break;
  }

  return ret;
}
}  // namespace cgzr

#endif /* __VISUALIZATION_DRAWABLE_DRAWABLE_TYPE__HPP__ */
