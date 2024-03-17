#include "mysqrt.h"

#include <iostream>

namespace mathfunctions {
namespace detail {
// 一个简单的黑客式的平方根计算
// 译注：这里使用的方法是牛顿法，也称为牛顿-拉弗森方法
// 通过不断地用切线逼近方程的根来逼近方程的解。
// 感兴趣的可以参考 https://zh.wikipedia.org/wiki/%E7%89%9B%E9%A1%BF%E6%B3%95 （维基百科） 
// 或者 https://baike.baidu.com/item/%E7%89%9B%E9%A1%BF%E8%BF%AD%E4%BB%A3%E6%B3%95 （百度）
double mysqrt(double x)
{
  if (x <= 0) {
    return 0;
  }

  double result = x;

  // 十次迭代
  for (int i = 0; i < 10; ++i) {
    if (result <= 0) {
      result = 0.1;
    }
    double delta = x - (result * result);
    result = result + 0.5 * delta / result;
    std::cout << "Computing sqrt of " << x << " to be " << result << std::endl;
  }
  return result;
}
}
}
