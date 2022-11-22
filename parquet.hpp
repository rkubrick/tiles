#ifndef _PARQUET_HPP_
#define _PARQUET_HPP_

#include <vector>

#include "strip.hpp"

class parquet: public std::vector<strip>
{
public:
  static const int strips = 11;

  friend std::ostream& operator<<(std::ostream& os, const parquet& obj);
    
public:
  parquet(): std::vector<strip>(strips) { }
    
  bool is_complete() const;     // all possible tiles laid down
  bool is_valid() const;        // parquet tiles layout is valid but might not be complete
};

#endif

