#ifndef __COMMON_GEOMETRY_FACTORY__HPP__
#define __COMMON_GEOMETRY_FACTORY__HPP__

#include "geometry/geometry_base.hpp"
#include "geometry/geometry_type.hpp"

namespace cgzr {

class GeometryFactory {
public:
  std::unique_ptr<GeometryBase> CreateRandom(GeometryType geometry_type,
                                             size_t size);
};

}  // namespace cgzr

#endif /* __COMMON_GEOMETRY_FACTORY__HPP__ */
