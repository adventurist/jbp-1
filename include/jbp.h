#include <math.h>
#include <util.h>

struct Bot {
  GeoLocation<float> location;
  Object* object;
  int orientation;

  Bot() : location(GeoLocation<float>{0.0f, 0.0f}), object(nullptr), orientation(0) {}

  ~Bot() {
    if (object != nullptr) {
      delete object;
    }
  }
  float measureDistanceTo(GeoLocation<float> destination) {
    return GeoLocation<float>::distanceBetween(location, destination);
  }

  void move(GeoLocation<float> destination) {
    location = GeoLocation<float>{destination.longitude, destination.latitude};
  }

  void scan() {
    orientation = getRandom<int>();
    location = getLocation();

    if (searchForObject()) { // luck of the draw
      // Object discovered. Determine location
      object = new Object{location};
      object->dimensions = measureObject(object);
    }
  }

  void transmitUART() {}
  void deployArm() {}
  void graspObject() {}
};
