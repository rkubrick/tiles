#include "parquet.hpp"
#include <algorithm>

using namespace std;

const int parquet::strips;

bool parquet::is_complete() const
{
  if( size() < strips )
    return false;
    
  for( int i = 0; i < size(); i++ )
    if( ! vector::operator[](i).is_complete() )
      return false;
  
  return true;
}
  
bool parquet::is_valid() const
{
  for( int i = 0; i < size(); i++ ) {
    if( ! vector::operator[](i).is_valid() )
      return false;

    if( i > 0 && ! vector::operator[](i).is_valid(vector::operator[](i-1)) )
      return false;
  }

  return true;
}

ostream& operator<<(ostream& os, const parquet& p)
{
  for( int i = 0; i < p.size(); i++ )
    os << p[i] << endl;

  return os;
}
