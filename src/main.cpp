// ----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"

#include "Timer.h"
#include "jbp.h"

#if defined(STM32F401xE)
#warning "Assume a NUCLEO-F401RE board, PA5, active high."
#elif defined(STM32F407xx)
#warning "Assume a STM32F4-Discovery board, PD12-PD15, active high."
#endif

Bot bot;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

int main(int argc, char* argv[]) {
  trace_dump_args(argc, argv);
  trace_puts("JBP Begin!");
  trace_printf("System clock: %u Hz\n", SystemCoreClock);

  Timer timer;
  timer.start ();
  timer.sleep (Timer::FREQUENCY_HZ);

  for (size_t i = 0; i < 50; ++i) {
	  scan(&bot);
	  trace_printf("Orientation is %d\n", bot.orientation);
	  trace_printf("Location is %f latitude and %f latitude\n", bot.location.latitude, bot.location.longitude);
    }

  timer.sleep (Timer::FREQUENCY_HZ);

  return 0;
}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
