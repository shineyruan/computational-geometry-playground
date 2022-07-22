#ifndef __VISUALIZATION_DRAWABLE_DRAWABLE_BASE__HPP__
#define __VISUALIZATION_DRAWABLE_DRAWABLE_BASE__HPP__

#include <unordered_set>
#include <vector>

#include "drawable_type.hpp"
#include "utils/include_eigen.hpp"

namespace cgzr {
namespace visualization {

class DrawableBase {
public:
  DrawableBase(DrawableType type = DrawableType::UNSUPPORTED) : type_(type) {}

protected:
  DrawableType type_;
};

}  // namespace visualization
}  // namespace cgzr

#endif /* __VISUALIZATION_DRAWABLE_DRAWABLE_BASE__HPP__ */
