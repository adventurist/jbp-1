#include "structs.h"

struct Bot {
  struct GeoL location;
  struct Object object;
  int orientation;
};

void scan(struct Bot* bot) {
  bot->location.latitude = bot->location.latitude + 3 * 0.9;
  bot->location.longitude = bot->location.longitude + 2 * 0.9;
  bot->orientation++;
  if (bot->orientation == 360) {
    bot->orientation = 0;
  }
}
