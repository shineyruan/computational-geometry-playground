#include "geometry_factory.hpp"

#include <spdlog/spdlog.h>

#include "geometry/points.hpp"

namespace cgzr {

std::unique_ptr<GeometryBase> GeometryFactory::CreateRandom(
    GeometryType geometry_type, size_t size) {
  switch (geometry_type) {
    case GeometryType::POINTS:
      return std::make_unique<Points>(size);

    default:
      SPDLOG_ERROR("Unsupported geometry type: {}", ToString(geometry_type));
      return nullptr;
  }
}

}  // namespace cgzr
