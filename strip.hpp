#ifndef _STRIP_HPP_
#define _STRIP_HPP_

#include <iostream>
#include <vector>
#include <set>

class strip: protected std::vector<int> {
public:
  static const int max_len = 30;
    
  static const int short_tile_len = 2;
  static const int long_tile_len = 3;
  static const int max_tiles = max_len / short_tile_len;

public:
  strip(): m_len(0) { reserve(max_tiles); }

  int len() const { return m_len; }
  int tiles() const { return size(); }
  bool is_valid() const { return max_len - m_len != 1; }
  bool is_valid(const strip& prev) const;
  bool is_complete() const { return max_len == m_len; }
  int last() const { return size() ? back() : 0; }
  bool add_short_tile();
  bool add_long_tile();

  int operator[](int idx) const { return idx >= size() ? 0 : std::vector<int>::operator[](idx); }

  friend std::ostream& operator<<(std::ostream& os, const strip& obj);

protected:
  int m_len;
  std::set<int> m_edges;
};

#endif

