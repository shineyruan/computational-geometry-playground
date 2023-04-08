#include "sciplot_visualizer.hpp"

#include "logging/logging.hpp"
#include "visualization/drawable/line_string.hpp"
#include "visualization/drawable/point_set.hpp"

namespace cgzr {
namespace visualization {

void SciplotVisualizer::Visualize() const {
  // Initialize plot
  sciplot::Plot2D plot;

  // Set the plot fonts
  plot.fontName("Palatino");
  plot.fontSize(12);
  plot.legend().atTop().fontSize(10).displayHorizontal().displayExpandWidthBy(
      2);

  // Set the x and y labels
  plot.xlabel("x").fontName("Palatino").fontSize(12);
  plot.ylabel("y").fontName("Palatino").fontSize(12);

  // Set the x and y ranges
  plot.xrange(world_min_.x() - PLOT_X_EXTEND_RATIO * std::abs(world_min_.x()),
              world_max_.x() + PLOT_X_EXTEND_RATIO * std::abs(world_max_.x()));
  plot.yrange(world_min_.y() - PLOT_Y_EXTEND_RATIO * std::abs(world_min_.y()),
              world_max_.y() + PLOT_Y_EXTEND_RATIO * std::abs(world_max_.y()));

  // Draw shapes
  for (const auto& drawable : drawables_) {
    switch (drawable->Type()) {
      case DrawableType::POINT_SET:
        DrawPointSet(plot, drawable.get());
        break;

      case DrawableType::LINE_STRING:
        DrawLineString(plot, drawable.get());

      default:
        break;
    }
  }

  // Create figure to hold plot
  sciplot::Figure fig = {{plot}};

  // Create canvas to hold figure
  sciplot::Canvas canvas = {{fig}};
  canvas.size(CANVAS_WIDTH, CANVAS_HEIGHT);

  // Display objects
  canvas.show();
}

void SciplotVisualizer::DrawPointSet(sciplot::Plot2D& plot,
                                     const DrawableBase* drawable) const {
  const PointSet* point_set = dynamic_cast<const PointSet*>(drawable);
  if (!point_set) {
    SPDLOG_ERROR("Invalid {} object!", ToString(drawable->Type()));
    return;
  }

  const auto& ps_vertices = point_set->Vertices();

  sciplot::Vec x(0., ps_vertices.size()), y(0., ps_vertices.size());

  for (size_t i = 0; i < ps_vertices.size(); ++i) {
    x[i] = ps_vertices.at(i).x();
    y[i] = ps_vertices.at(i).y();
  }

  plot.drawPoints(x, y);
}

void SciplotVisualizer::DrawLineString(sciplot::Plot2D& plot,
                                       const DrawableBase* drawable) const {
  const LineString* line_string = dynamic_cast<const LineString*>(drawable);
  if (!line_string) {
    SPDLOG_ERROR("Invalid {} object!", ToString(drawable->Type()));
    return;
  }

  const auto& ls_vertices = line_string->Vertices();
  const auto& ls_edges = line_string->Edges();

  sciplot::Vec x(0., 2 * ls_edges.size()), y(0., 2 * ls_edges.size());

  for (size_t i = 0; i < ls_edges.size(); ++i) {
    x[2 * i] = ls_vertices.at(ls_edges.at(i).first).x();
    y[2 * i] = ls_vertices.at(ls_edges.at(i).first).y();
    x[2 * i + 1] = ls_vertices.at(ls_edges.at(i).second).x();
    y[2 * i + 1] = ls_vertices.at(ls_edges.at(i).second).y();
  }

  plot.drawCurve(x, y);
}

}  // namespace visualization
}  // namespace cgzr
