#ifndef _DESIGNER_HPP_
#define _DESIGNER_HPP_

#include <list>

#include "parquet.hpp"

class designer
{
public:
  designer(): m_first_row_completed(0) { }
  void generate();
    
  const std::list<parquet>& parquets() const { return m_parquets; }
  int first_row_completed() const { return m_first_row_completed; }

protected:
  void add_first_strip_tile(parquet p);
  void add_next_strip_tile(parquet& p, int prev_strip);

protected:
  int m_first_row_completed;
  std::list<parquet> m_parquets;
};

#endif
