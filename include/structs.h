
struct Dimensions {
  unsigned int height;
  unsigned int width;
  unsigned int length;
};

struct GeoL {
  long double longitude;
  long double latitude;
};

struct Object {
  struct Dimensions dimensions;
  struct GeoL location;
};

