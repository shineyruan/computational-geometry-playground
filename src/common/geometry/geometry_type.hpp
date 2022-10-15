#ifndef __COMMON_GEOMETRY_GEOMETRY_TYPES__HPP__
#define __COMMON_GEOMETRY_GEOMETRY_TYPES__HPP__

#include <string>

namespace cgzr {
enum class GeometryType { UNKNOWN = 0, POINTS_2D, LINES_2D, POLYGON_2D };

inline std::string ToString(GeometryType type) {
  switch (type) {
    case GeometryType::UNKNOWN:
      return "UNKNOWN";
    case GeometryType::POINTS_2D:
      return "POINTS_2D";
    case GeometryType::LINES_2D:
      return "LINES_2D";
    case GeometryType::POLYGON_2D:
      return "POLYGON_2D";
    default:
      return "ERROR";
  }
}

}  // namespace cgzr

#endif /* __COMMON_GEOMETRY_GEOMETRY_TYPES__HPP__ */
