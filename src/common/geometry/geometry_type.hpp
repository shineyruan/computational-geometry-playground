#ifndef __COMMON_GEOMETRY_GEOMETRY_TYPES__HPP__
#define __COMMON_GEOMETRY_GEOMETRY_TYPES__HPP__

#include <string>

namespace cgzr {
enum class GeometryType { UNKNOWN = 0, POINTS, POLYGON };

inline std::string ToString(GeometryType type) {
  switch (type) {
    case GeometryType::UNKNOWN:
      return "UNKNOWN";
    case GeometryType::POINTS:
      return "POINTS";
    case GeometryType::POLYGON:
      return "POLYGON";
    default:
      return "ERROR";
  }
}

}  // namespace cgzr

#endif /* __COMMON_GEOMETRY_GEOMETRY_TYPES__HPP__ */
