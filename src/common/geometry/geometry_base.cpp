#include "common/geometry/geometry_base.hpp"

#include <spdlog/spdlog.h>

#include "all_geometries.hpp"

namespace cgzr {

std::unique_ptr<GeometryBase> GeometryBase::Create(GeometryType type) {
  switch (type) {
    case GeometryType::POINTS_2D:
      return std::make_unique<Points2d>();
    case GeometryType::LINES_2D:
      return std::make_unique<Lines2d>();
    default:
      SPDLOG_ERROR("Type {} is not supported.", ToString(type));
      break;
  }
  return nullptr;
}

std::unique_ptr<GeometryBase> GeometryBase::CreateRandom(GeometryType type,
                                                         size_t size) {
  switch (type) {
    case GeometryType::POINTS_2D:
      return std::make_unique<Points2d>(size);
    case GeometryType::LINES_2D:
      return std::make_unique<Lines2d>(size);
    default:
      SPDLOG_ERROR("Type {} is not supported.", ToString(type));
      break;
  }

  return nullptr;
}

}  // namespace cgzr
