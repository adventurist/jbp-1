#include "structs.h"

struct Bot {
  struct GeoL location;
  Object* object;
  int orientation;

  ~Bot() {
	  if (object != nullptr) {
		  delete object;
	  }
  }
  float targetObject() {
	  if (object != nullptr) {
	    float lg_distance = location.longitude - object->location.longitude;
	    float la_distance = location.latitude - object->location.latitude;

	    return lg_distance + la_distance;
	  }
	  return 0.0F;
  }
  
  void approach(GeoL destination) {
	  if (object != nullptr) {
		  location.longitude = destination.longitude;
		  location.latitude = destination.latitude;
	  }
  }

  void transmitUART() {
	  // update and synchronize controller states
  }

  void deployArm() {
	  // deploy
  }

  void graspObject() {

  }



};

void scan(struct Bot* bot) {
  bot->location.latitude = bot->location.latitude + 3 * getRandom();
  bot->location.longitude = bot->location.longitude + 2 * getRandom();
  bot->orientation = bot->orientation + getRandom();
  if (bot->orientation == 360) {
    bot->orientation = 0;
  }
  if (getRandom() > 5) {
	  bot->object = new Object{};
	  bot->object->dimensions = Dimensions{.height = getRandom(), .width = getRandom(), .length = getRandom()};
	  bot->object->location = GeoL{.longitude = 180 / getRandom(), .latitude = 90 / getRandom()};
  }
}


