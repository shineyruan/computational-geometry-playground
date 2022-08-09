#include "opencv_visualizer.hpp"

#include <spdlog/spdlog.h>

#include <limits>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "visualization/drawable/line_string.hpp"
#include "visualization/drawable/point_set.hpp"

namespace cgzr {
namespace visualization {

void OpenCVVisualizer::Visualize() const {
  // Initialize canvas (default to be white)
  cv::Mat canvas{IMAGE_HEIGHT + 2 * IMAGE_HEIGHT_BUFFER,
                 IMAGE_WIDTH + 2 * IMAGE_WIDTH_BUFFER, CV_8UC3,
                 cv::Scalar(255, 255, 255)};

  // Compute offset and scaling
  auto [offset, scaling] = ComputeOffsetAndScaling();

  // Draw shapes
  for (const auto& drawable : drawables_) {
    switch (drawable->Type()) {
      case DrawableType::POINT_SET:
        DrawPointSet(canvas, drawable.get(), offset, scaling);
        break;

      case DrawableType::LINE_STRING:
        DrawLineString(canvas, drawable.get(), offset, scaling);

      default:
        break;
    }
  }

  // Display shapes
  cv::imshow("Visualize", canvas);
  cv::waitKey(0);
}

void OpenCVVisualizer::DrawPointSet(cv::Mat& canvas,
                                    const DrawableBase* drawable,
                                    const Eigen::Vector2d offset,
                                    const Eigen::Vector2d scaling) const {
  const PointSet* point_set = dynamic_cast<const PointSet*>(drawable);
  if (!point_set) {
    spdlog::error("Invalid {} object!", ToString(drawable->Type()));
    return;
  }

  for (const auto& vert : point_set->Vertices()) {
    int vert_x = static_cast<int>((vert.x() - offset.x()) * scaling.x());
    int vert_y = static_cast<int>((vert.y() - offset.y()) * scaling.y());
    cv::Point2i cv_vert{vert_y, vert_x};
    cv::circle(canvas,
               cv_vert + cv::Point2i(IMAGE_HEIGHT_BUFFER, IMAGE_WIDTH_BUFFER),
               POINT_RADIUS, cv::Scalar(0, 0, 255), -1);
  }
}

void OpenCVVisualizer::DrawLineString(cv::Mat& canvas,
                                      const DrawableBase* drawable,
                                      const Eigen::Vector2d offset,
                                      const Eigen::Vector2d scaling) const {
  const LineString* line_string = dynamic_cast<const LineString*>(drawable);
  if (!line_string) {
    spdlog::error("Invalid {} object!", ToString(drawable->Type()));
    return;
  }

  // visualize points
  for (const auto& vert : line_string->Vertices()) {
    int vert_x = static_cast<int>((vert.x() - offset.x()) * scaling.x());
    int vert_y = static_cast<int>((vert.y() - offset.y()) * scaling.y());
    cv::Point2i cv_vert{vert_y, vert_x};
    cv::circle(canvas,
               cv_vert + cv::Point2i(IMAGE_HEIGHT_BUFFER, IMAGE_WIDTH_BUFFER),
               POINT_RADIUS, cv::Scalar(0, 0, 255), -1);
  }

  // visualize lines
  for (const auto& edge : line_string->Edges()) {
    auto [p1_idx, p2_idx] = edge;
    int p1_x = static_cast<int>(
        (line_string->Vertices()[p1_idx].x() - offset.x()) * scaling.x());
    int p1_y = static_cast<int>(
        (line_string->Vertices()[p1_idx].y() - offset.y()) * scaling.y());
    int p2_x = static_cast<int>(
        (line_string->Vertices()[p2_idx].x() - offset.x()) * scaling.x());
    int p2_y = static_cast<int>(
        (line_string->Vertices()[p2_idx].y() - offset.y()) * scaling.y());
    cv::Point2i cv_p1{p1_y, p1_x}, cv_p2{p2_y, p2_x};
    cv::line(canvas,
             cv_p1 + cv::Point2i(IMAGE_HEIGHT_BUFFER, IMAGE_WIDTH_BUFFER),
             cv_p2 + cv::Point2i(IMAGE_HEIGHT_BUFFER, IMAGE_WIDTH_BUFFER),
             cv::Scalar(255, 0, 0), LINE_THICKNESS, cv::LINE_AA);
  }
}

std::pair<Eigen::Vector2d, Eigen::Vector2d>
OpenCVVisualizer::ComputeOffsetAndScaling() const {
  Eigen::Vector2d offset = -world_min_;
  double scaling = std::min(IMAGE_WIDTH / (world_max_ - world_min_).x(),
                            IMAGE_HEIGHT / (world_max_ - world_min_).y());
  return std::make_pair(offset, Eigen::Vector2d(scaling, scaling));
}

}  // namespace visualization
}  // namespace cgzr
