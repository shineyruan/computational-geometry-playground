#include <sciplot/sciplot.hpp>

int main(int argc, char const *argv[]) {
  // Create values for your x-axis
  sciplot::Vec x = sciplot::linspace(0.0, 5.0, 100);

  // Create a Plot object
  sciplot::Plot plot;

  // Set color palette
  plot.palette("set2");

  // Draw a sine graph putting x on the x-axis and sin(x) on the y-axis
  plot.drawCurve(x, std::sin(x)).label("sin(x)").lineWidth(4);

  // Draw a cosine graph putting x on the x-axis and cos(x) on the y-axis
  plot.drawCurve(x, std::cos(x)).label("cos(x)").lineWidth(4);

  // Show the plot in a pop-up window
  plot.show();
  return 0;
}
