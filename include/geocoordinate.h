#ifndef __geocoordinates_h__
#define __geocordinates_h__

#include <type_traits>
#include <utility>
#include <limits>

// Replace default tuple access interface
#define First(x) std::get<0>(x)
#define Second(x) std::get<1>(x)

/**
 * GeoCoordinate of type Longitude or Latitude
 */
template <typename T>
class GeoCoordinate {
  typedef T DegreeValue;
  typedef std::pair<T, T> CoordPair;

 public:
  typedef DegreeValue Longitude;
  typedef DegreeValue Latitude;

  /**
   * Coordinate with overloads
   */
  template <typename NumericalType>
  struct Coordinate {
    DegreeValue degree;
    T limit;

    Coordinate(T value) : degree(value) {
      if constexpr (std::is_same_v<NumericalType, Longitude>) {
        limit = 180;
      } else if constexpr (std::is_same_v<NumericalType, Latitude>) {
        limit = 90;
      } else {
    	limit = std::numeric_limits<NumericalType>::max(); // error
      }
    }

    /**
     * Overload operators to constrain range
     */
    Coordinate operator+(const Coordinate& other) {
      CoordPair p{this->degree, other.degree};
      if ((First(p) + Second(p)) > limit) {
        auto diff = limit - First(p);
        auto remain = Second(p) - diff;
        return (Coordinate(0 - remain));
      }
      return Coordinate(First(p) + Second(p));
    }

    Coordinate operator-(const Coordinate& other) {
      CoordPair p{this->degree, other.degree};
      if ((First(p) - Second(p)) < -limit) {
        auto diff = -limit - First(p);
        auto remain = diff - Second(p);
        return Coordinate(0 - remain);
      }
      return Coordinate(First(p) - Second(p));
    }
  };
  // The coordinate value member
  Coordinate<T> value;
};

/**
 * GeoLocation
 */
template <typename T>
class GeoLocation {
 public:
  /**
   * constructor
   */
  GeoLocation<T>(T lng, T lat) : longitude(lng), latitude(lat) {}
  /* members */
  typename GeoCoordinate<T>::Longitude longitude;
  typename GeoCoordinate<T>::Latitude latitude;
/**
 * Utility function
 */
  static T distanceBetween(GeoLocation<T> origin, GeoLocation<T> destination) {
	// implement - http://www.movable-type.co.uk/scripts/latlong-vincenty.html
    return T{};
  }
};
#endif // __geocoordinates_h__
