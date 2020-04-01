
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

