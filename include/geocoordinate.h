#include <type_traits>
#include <utility>

#define First(x) std::get<0>(x)
#define Second(x) std::get<1>(x)

template <typename T>
class GeoCoordinate {
  typedef T DegreeValue;
  typedef std::pair<T, T> CoordPair;

 public:
  typedef DegreeValue Longitude;
  typedef DegreeValue Latitude;
  template <typename NumericalType>
  struct Coordinate {
    DegreeValue degree;
    T limit;
    Coordinate(T value) : degree(value) {
      if constexpr (std::is_same_v<NumericalType, Longitude>) {
        limit = 180;
      } else if constexpr (std::is_same_v<NumericalType, Latitude>) {
        limit = 90;
      }
    }
    Coordinate operator+(const Coordinate& other) {
      auto long_this = *this;
      auto l1 = long_this.degree;
      auto l2 = other.degree;
      CoordPair p{l1, l2};

      if ((First(p) + Second(p)) > limit) {
        auto diff = limit - First(p);
        auto remain = Second(p) - diff;
        return (Coordinate(0 - remain));
      }
      return Coordinate(First(p) + Second(p));
    }

    Coordinate operator-(const Coordinate& other) {
      auto long_this = *this;
      auto l1 = long_this.degree;
      auto l2 = other.degree;

      CoordPair p{l1, l2};

      if ((First(p) - Second(p)) < -limit) {
        auto diff = -limit - First(p);
        auto remain = diff - Second(p);
        return Coordinate(0 - remain);
      }
      return Coordinate(First(p) - Second(p));
    }
  };
  // Member
  Coordinate<T> value;
};

template <typename T>
class GeoLocation {

 public:
  GeoLocation<T>(T lng, T lat) : longitude(lng), latitude(lat) {}

  typename GeoCoordinate<T>::Longitude longitude;
  typename GeoCoordinate<T>::Latitude latitude;

  static T distanceBetween(GeoLocation<T> origin, GeoLocation<T> destination) {
    return T{};
  }
};
