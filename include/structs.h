#include <random>

#include <stdexcept>
#include <sstream>


struct Dimensions {
  unsigned int height;
  unsigned int width;
  unsigned int length;
};

struct GeoL {
  float longitude;
  float latitude;
};

struct Object {
  struct Dimensions dimensions;
  struct GeoL location;
};

int getRandom(int min = 1, int max = 10) {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(min, max);
	return dist(mt);
}
