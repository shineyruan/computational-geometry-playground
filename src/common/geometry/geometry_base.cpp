#include "common/geometry/geometry_base.hpp"

#include <spdlog/spdlog.h>

#include "points2d.hpp"

namespace cgzr {

std::unique_ptr<GeometryBase> CreateRandom(GeometryType type, size_t size) {
  switch (type) {
    case GeometryType::POINTS_2D:
      return std::make_unique<Points2d>(size);
    default:
      SPDLOG_ERROR("Type {} is not supported.", ToString(type));
      break;
  }

  return nullptr;
}

}  // namespace cgzr
