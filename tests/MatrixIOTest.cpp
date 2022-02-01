#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "matrixIO.hpp"

BOOST_AUTO_TEST_SUITE(MatrixIOTests)

BOOST_AUTO_TEST_CASE(openData)
{
  const std::string fileToOpen = "../data/m3.csv";
  const int                             matrixSize{3};
  Eigen::MatrixXd expectedMatrix(3, 3);
  expectedMatrix << 0.680375, 0.59688, -0.329554,
                    -0.211234, 0.823295, 0.536459,
                    0.566198, -0.604897, -0.444451;

  Eigen::MatrixXd returned_matrix = matrixIO::openData(fileToOpen, matrixSize);
  BOOST_TEST(expectedMatrix == returned_matrix); // Should work without rounding errors because no additions/... made.
}

BOOST_AUTO_TEST_SUITE_END()
