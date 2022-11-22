#include <iostream>

#include "designer.hpp"

using namespace std;

int main()
{
  designer mydesigner;

  mydesigner.generate();
  auto p = mydesigner.parquets();
  clog << "First Rows " << mydesigner.first_row_completed() << endl;
  clog << "Total solutions " << p.size() << endl;
  clog << "Checking solutions..." << endl;
  for( auto it = p.begin(); it != p.end(); ++it ) {
    parquet& tp = *it;
    if( ! tp.is_valid() ) {
      clog << "Invalid solution " << endl << tp << endl;
      return -1;
    }
  }
  clog << "All " << p.size() << " solutions are valid" << endl;

  return 0;
}

