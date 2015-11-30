#include <iostream>

using std::cout;
using std::endl;
using std::size_t;

void slda_print(int** a, size_t nrows, size_t ncols) {
  for (size_t i = 0; i < nrows; ++i) {
    bool comma = false;
    cout << "[";
    for (size_t j = 0; j < ncols; ++j) {
      if (comma) {
        cout << ", ";
      } else {
        comma = true;
      }
      cout << a[i][j];
    }
    cout << "]" << endl;
  }
}

void slda_print_ptr(int** a, size_t nrows, size_t ncols) {
  cout << "size of item in bytes: " << sizeof(**a) << endl;
  cout << "nrows: " << nrows << endl;
  cout << "ncols: " << ncols << endl;
  cout << "a = " << a << endl;
  for (size_t i = 0; i < nrows; ++i) {
    cout << "a[" << i << "] = " << a[i] << endl;
  }
}

int** slda_alloc(size_t nrows, size_t ncols) {
  // allocate array for data
  int* data = new int[nrows*ncols];
  // allocate array for row pointers
  int** slda = new int*[nrows];
  // assign row pointers
  for (size_t i = 0; i < nrows; ++i) {
    // here we are doing pointer arithmetic
    slda[i] = data + i*ncols;
  }
  return slda;
}

void slda_free(int** a) {
  // delete array for data
  delete [] a[0];
  // delete array for pointers
  delete [] a;
}

void slda_zero(int** a, size_t nrows, size_t ncols) {
  for (size_t i = 0; i < nrows; ++i) {
    for (size_t j = 0; j < ncols; ++j) {
      a[i][j] = 0;
    }
  }
}

int main() {
  size_t nrows = 4;
  size_t ncols = 6;
  int** a = slda_alloc(nrows,ncols);
  slda_zero(a,nrows,ncols);
  a[2][2] = 55;
  slda_print_ptr(a,nrows,ncols);
  slda_print(a,nrows,ncols);
  slda_free(a);
  return 0;
}
