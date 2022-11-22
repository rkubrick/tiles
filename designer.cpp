#include "designer.hpp"

#include <iostream>
using namespace std;

void designer::generate()
{
  add_first_strip_tile(parquet());
}

void designer::add_first_strip_tile(parquet p)
{
  if( p[0].is_complete() ) {
    ++m_first_row_completed;
    return;
  }

  if( ! p[0].is_valid() )
    return;

  parquet p1 = p;
  parquet p2 = p;

  if( p1[0].add_short_tile() ) {
    add_next_strip_tile(p1, 0);
    add_first_strip_tile(p1);
  }

  if( p2[0].add_long_tile() ) {
    add_next_strip_tile(p2, 0);      
    add_first_strip_tile(p2);
  }
}


void designer::add_next_strip_tile(parquet& p, int prev_strip)
{
  int curr_strip = prev_strip + 1;
  int len_diff = p[prev_strip].len() - p[curr_strip].len();
  
  if( p.is_complete() ) {
    //cout << "completed parquet at strip " << curr_strip << endl << p << endl;
    m_parquets.push_back(p);
    return;
  }

  /*
    XXX: this should never happen. all conditions should be handled in the switch( len_diff ) below
  if( ! p.is_valid() )
    return;
  */

  if( curr_strip >= parquet::strips )
    return;

  switch( len_diff ) {
  case 2:
    if( p[prev_strip].is_complete() ) {
      p[curr_strip].add_short_tile();
      add_next_strip_tile(p, curr_strip);
    }
    break;
      
  case 3:
    if( p[prev_strip].is_complete() ) {
      p[curr_strip].add_long_tile();
      add_next_strip_tile(p, curr_strip);
    } else {
      p[curr_strip].add_short_tile();
      add_next_strip_tile(p, curr_strip);
    }
    break;
      
  case 4:
    // possible cases are prev strip 33 and 22 when at the top of the strip
    // two different current strip solutions if the prev strip last tile is 3
    if( p[prev_strip].last() == strip::long_tile_len ) {
      parquet p1 = p;
      p1[curr_strip].add_short_tile();
      add_next_strip_tile(p1, curr_strip);
      if( p1[prev_strip].is_complete() ) {
          p1[curr_strip].add_short_tile();
          add_next_strip_tile(p1, curr_strip);
      }
    }

    // long tile is a valid solution regardless of last previous tile
    p[curr_strip].add_long_tile();
    add_next_strip_tile(p, curr_strip);
    break;
      
  case 5:
    // possible cases are prev strip 233 or 23 when at the top of the strip
    // only current strip solution is 3
    p[curr_strip].add_long_tile();
    add_next_strip_tile(p, curr_strip);
    if( p[prev_strip].is_complete() ) {
      p[curr_strip].add_short_tile();
      add_next_strip_tile(p, curr_strip);
    }
    break;
        
  default:
    cout << "strip " << curr_strip << " len diff " << len_diff << " no condition handled " << endl << p << endl;
    assert(0);
  }
}
