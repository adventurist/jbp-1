// ----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <diag/Trace.h>

#include <Timer.h>
#include <jbp.h>

#if defined(STM32F401xE)
#warning "Assume a NUCLEO-F401RE board, PA5, active high."
#elif defined(STM32F407xx)
#warning "Assume a STM32F4-Discovery board, PD12-PD15, active high."
#endif

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

int main(int argc, char* argv[]) {
  trace_dump_args(argc, argv);
  trace_printf("System clock: %u Hz\n", SystemCoreClock);

  Timer timer;
  timer.start ();
  timer.sleep (Timer::FREQUENCY_HZ);

  Bot bot;

  do {
    bot.scan();
	  trace_printf(
      "Orientation is %d\nLocation is %f latitude and %f latitude\n",
      bot.orientation,
      bot.location.latitude,
      bot.location.longitude
    );

	  if (bot.object != nullptr) {
        trace_printf("Object found\n");
        bot.deployArm();
        bot.graspObject();

        GeoLocation<float> destination = getLocation();
        float distance_to_destination = bot.measureDistanceTo(destination);
        trace_printf("Distance to destination: %f\n ", distance_to_destination);

        if (distance_to_destination > 0.0) {
        	bot.move(destination);
        }
	  }
  } while (bot.object == nullptr); // No object

  timer.sleep (Timer::FREQUENCY_HZ);

  return 0;
}
#pragma GCC diagnostic pop
// ----------------------------------------------------------------------------
