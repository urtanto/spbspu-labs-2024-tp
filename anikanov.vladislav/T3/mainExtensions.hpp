#ifndef MAINEXTENSIONS_HPP
#define MAINEXTENSIONS_HPP

#include <functional>
#include <string>
#include "vector"
#include "polygon.hpp"

namespace anikanov {
  std::vector< Polygon > readPolygons(const std::string &filename);
  std::vector< double > getAreas(const std::vector< Polygon > &polygons);
  std::vector< double > getAreasIf(const std::vector< Polygon > &polygons, std::function< bool(const Polygon &) >);
  std::vector< size_t > getVertexes(const std::vector< Polygon > &polygons);
  double area(const std::vector< Polygon > &polygons, std::istream &in);
  void min(const std::vector< Polygon > &polygons, std::istream &in, std::ostream &out);
  void max(const std::vector< Polygon > &polygons, std::istream &in, std::ostream &out);
  size_t count(const std::vector< Polygon > &polygons, std::istream &in);
  size_t rects(const std::vector< Polygon > &polygons);
  size_t rightShapes(const std::vector< Polygon > &polygons);
}

#endif