#include "strip.hpp"

using namespace std;

const int strip::max_len;

const int strip::short_tile_len;
const int strip::long_tile_len;
const int strip::max_tiles;

bool strip::add_short_tile()
{
  if( m_len > max_len - short_tile_len )
    return false;

  push_back(short_tile_len);
  m_len += short_tile_len;
  if( m_len < max_len )
    m_edges.insert(m_len);
  
  return true;
}

bool strip::add_long_tile()
{
  if( m_len > max_len - long_tile_len )
    return false;

  push_back(long_tile_len);
  m_len += long_tile_len;
  if( m_len < max_len )
    m_edges.insert(m_len);
  
  return true;
}

bool strip::is_valid(const strip& prev) const
{
  set<int> common_edges;
  set_intersection(prev.m_edges.begin(), prev.m_edges.end(),
                   m_edges.begin(), m_edges.end(),
                   inserter(common_edges, common_edges.begin()));
  
  return common_edges.size() == 0;
}

ostream& operator<<(ostream& os, const strip& obj)
{
  for( auto it = obj.begin(); it != obj.end(); ++it )
    os << *it;

  return os;
}
