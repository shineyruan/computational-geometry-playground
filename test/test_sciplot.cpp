#include <sciplot/sciplot.hpp>
using namespace sciplot;

int main(int argc, char** argv) {
  // Create a vector with values from 0 to pi divided into 200 uniform intervals
  // for the x-axis
  Vec x = linspace(0.0, PI, 200);

  // Create a Plot object
  Plot2D plot;

  // Set the x and y labels
  plot.xlabel("x");
  plot.ylabel("y");

  // Set the x and y ranges
  plot.xrange(0.0, PI);
  plot.yrange(0.0, 1.0);

  // Set the legend to be on the bottom along the horizontal
  plot.legend().atOutsideBottom().displayHorizontal().displayExpandWidthBy(2);

  // Plot sin(i*x) from i = 1 to i = 6
  plot.drawCurve(x, std::sin(1.0 * x)).label("sin(x)");
  plot.drawCurve(x, std::sin(2.0 * x)).label("sin(2x)");
  plot.drawCurve(x, std::sin(3.0 * x)).label("sin(3x)");
  plot.drawCurve(x, std::sin(4.0 * x)).label("sin(4x)");
  plot.drawCurve(x, std::sin(5.0 * x)).label("sin(5x)");
  plot.drawCurve(x, std::sin(6.0 * x)).label("sin(6x)");

  plot.drawCurve(Vec({0., 0.5, 1.}), Vec({0., 0.5, 0.5})).label("y=x");

  // Create figure to hold plot
  Figure fig = {{plot}};
  // Create canvas to hold figure
  Canvas canvas = {{fig}};
  canvas.size(600, 300);

  canvas.show();

  // Save the plot to a PNG file
  canvas.save("example-sine-functions.svg");
}
