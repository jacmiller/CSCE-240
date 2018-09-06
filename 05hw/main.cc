#include "main.h"

void GenerateInterface() {
  cout << "Usage:" << endl;
  cout << "  (1) calc poly.in + number_x number_y" << endl;
  cout << "  (2) calc poly.in + offsets.in polys.out" << endl;
  cout << "  (3) calc poly.in x number_scalar number_x number_y" << endl;
  cout << "  (4) calc poly.in x by.in about.in polys.out" << endl;
}

int main(int argc, char** argv) {
  // begin inspecting arguments
  if (argc < 5 || 6 < argc){
    GenerateInterface();
    return 1;
  }
    
  ifstream poly_in;
  poly_in.open(argv[1]);  // Opens stream based argument '1'
  if (poly_in.fail()) {
    cerr << "Opening failed on " << argv[1] << " path correct?" << endl;
    return 1;
  }
  int count;
  poly_in >> count;
  if (3 > count) {
    cerr << "File poly.in has less than 3 points." << endl;
    return 1;
  }
  Point2d* points = new Point2d[count];
  for (int i = 0; i < count; ++i) {
    if (poly_in.eof()) {
      cerr << "File poly.in has less points than indicated" << endl;
      return 1;
    }
    poly_in >> points[i];
  }

  poly_in.close();

  Polygon *gon = new Polygon();
  delete[] points;

  switch (gon->Init(points, count)) {
  case Polygon::k_init_not_polygon_:
    cerr << "Polygon in poly.in is not a polygon" << endl;
    delete gon;
    return 1;

  case Polygon::k_init_nonunique_:
    cerr << "nonunique called because no arguments input yet" << endl;
    delete gon;
    return 1;

  case Polygon::k_init_has_collinear_:
    cerr << "polygon in poly.in has collinear vertices" << endl;
    delete gon;
    return 1;

  default:
    break;
  }
  

  if (argc == 5 && string(argv[2]) != "+")
    cerr << "if you're passing 5 arguments then it must include a '+'" << endl;
  else if (argc == 6 && string(argv[2]) != "x")
    cerr << "if you're passing 6 arguments then it must include a 'x'" << endl;

  double x, y;
  if (ExtractDouble(argv[3], x)) {
    if (ExtractDouble(argv[4], y, true)) {
      gon->Offset(Vector2d(x, y));
      cout << *gon << endl;
      return 0;
    } else {
      cerr << "You didn't pass in a second double, you passed in: "
        << argv[4] << endl;
      return 1;
    }
  }

  // Usage (2) started
  // Reading offsets.in

  ifstream offsets_in;
  offsets_in.open(argv[3]);  // Opens based on argument 4
  if (offsets_in.fail())
    cerr << argv[3] << " didn't open, check your file name/path" << endl;

  offsets_in >> count;

  Vector2d* vectors = new Vector2d[count];
  for (int i = 0; i < count; ++i) {
    if (poly_in.eof()) {
      cerr << "File offsets.in has less vectors than indicated" << endl;
      return 1;
    }
    offsets_in >> vectors[i];
  }
  offsets_in.close();

  // Creating the polys_out

  ofstream polys_out;
  polys_out.open(argv[4]);

  for (int i = 0; i < count; ++i) {
    // polys_out << *gon << endl;
    Polygon tmp;
    tmp = *gon;
    tmp.Offset(vectors[i]);
    polys_out << tmp << endl;
  }
  polys_out.close();
}

bool ExtractDouble(const char* cstr_dbl, double &d, bool verbose) {
  char *pEnd;
  d = strtod(cstr_dbl, &pEnd);
  if (pEnd == cstr_dbl) {
    if (verbose) {
      cout << "The value " << cstr_dbl
        << " is not a double usage message." << endl;
    }
    return false;
  }
  return true;
}

