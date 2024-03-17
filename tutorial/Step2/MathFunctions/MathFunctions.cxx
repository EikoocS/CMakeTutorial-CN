#include "MathFunctions.h"

// TODO 11: include cmath

// TODO 10: 根据 USE_MYMATH 将 mysqrt 包含在预编译的 ifdef 中
#include "mysqrt.h"

namespace mathfunctions {
double sqrt(double x)
{
  // TODO 9: 如果定义了 USE_MYMATH，则使用 detail::mysqrt 否则使用 std::sqrt。
  return detail::mysqrt(x);
}
}
