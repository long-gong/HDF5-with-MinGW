#include <highfive/H5Easy.hpp>

int main()
{
    H5Easy::File file("example.h5", H5Easy::File::Overwrite);

    int A = 100;

    H5Easy::dump(file, "/example/A", A);

    A = H5Easy::load<int>(file, "/example/A");

    std::cout << "A: " << A << std::endl;

    return 0;
}