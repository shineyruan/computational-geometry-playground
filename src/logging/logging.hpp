#ifndef SRC_LOGGING_LOGGING_HPP_
#define SRC_LOGGING_LOGGING_HPP_

#include <spdlog/fmt/ostr.h>
#include <spdlog/spdlog.h>

#include "utils/include_eigen.hpp"

template <>
struct fmt::formatter<Eigen::Transpose<Eigen::Vector3d>> : ostream_formatter {};

template <>
struct fmt::formatter<Eigen::Transpose<Eigen::Vector2d>> : ostream_formatter {};

#endif /* SRC_LOGGING_LOGGING_HPP_ */
