// 一个计算数字平方根的小程序
#include <cmath>
#include <cstdlib> // TODO 5: 移除此行
#include <iostream>
#include <string>

// TODO 11: 引入 TutorialConfig.h

int main(int argc, char* argv[])
{
  if (argc < 2) {
    // TODO 12: 创建一个使用 Tutorial_VERSION_MAJOR 和 Tutorial_VERSION_MINOR 的输出语句
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;
  }

  // 将输入转换为双精度浮点数
  // TODO 4: 将 atof(argv[1]) 替换为 std::stod(argv[1])
  const double inputValue = atof(argv[1]);

  // 计算平方根
  const double outputValue = sqrt(inputValue);
  std::cout << "The square root of " << inputValue << " is " << outputValue
            << std::endl;
  return 0;
}
