#if __INTELLISENSE__
#undef __ARM_NEON
#undef __ARM_NEON__
#endif

#include <spdlog/fmt/ostr.h>
#include <spdlog/spdlog.h>

#include <Eigen/Dense>

int main(int argc, char const *argv[]) {
  Eigen::Vector3d v;
  v << 1.0, 2.0, 3.0;
  spdlog::info("Printing Eigen vector: {}", v.transpose());
  return 0;
}
