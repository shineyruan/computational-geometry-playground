#ifndef SRC_COMMON_GEOMETRY_GEOMETRY_TYPE_HPP_
#define SRC_COMMON_GEOMETRY_GEOMETRY_TYPE_HPP_

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

#endif  // SRC_COMMON_GEOMETRY_GEOMETRY_TYPE_HPP_
