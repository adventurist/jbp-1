#include <random>
#include <sstream>
#include <stdexcept>
#include <geocoordinate.h>


struct Dimensions {
  unsigned int height;
  unsigned int width;
  unsigned int length;
};

struct Object {
  struct Dimensions dimensions;
  GeoLocation<float> location;

  Object(GeoLocation<float> location) : location(location) {}
};

/**
 * Poor man's number gen
 */
template <typename T>
T getRandom(T min = 1, T max = 10) {
  int random{};
  while (!(random >= min && random <= max)) {
    random = rand() / 100000000;
  }
  return random;
}

/**
 * Discovery
 */
GeoLocation<float> getLocation() {
  return GeoLocation<float>{
    180.0f / getRandom<float>(),
    90.0f / getRandom<float>()
  };
}

/**
 *
 */
bool searchForObject () {
  return getRandom<float>() > 8;
};

/**
 * Measure dimensions of object
 */
Dimensions measureObject(Object* object) {
  return Dimensions{
      .height = getRandom<uint16_t>(),
      .width = getRandom<uint16_t>(),
      .length = getRandom<uint16_t>()
    };
}
