// 计算一个数字平方根的简单程序
#include <cmath>
#include <iostream>
#include <string>

// TODO 5: Include MathFunctions.h
#include "TutorialConfig.h"

int main(int argc, char* argv[])
{
  if (argc < 2) {
    // 输出版本信息
    std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
              << Tutorial_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;
  }

  // 将输入的字符串转换为 double
  const double inputValue = std::stod(argv[1]);

  // TODO 6: 使用 mathfunctions::sqrt 替换 std::sqrt

  // 计算平方根
  const double outputValue = sqrt(inputValue);
  std::cout << "The square root of " << inputValue << " is " << outputValue
            << std::endl;
  return 0;
}
