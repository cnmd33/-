/*
创建一个类 `Vector`，该类表示一个二维向量，并实现向量相加的功能。
### C++ 要求
1. 创建一个类 `Vector`，包含两个私有成员变量 `x` 和 `y`，表示向量的两个分量。
2. 提供一个构造函数来初始化这两个成员变量。
3. 提供一个公共方法 `add`，该方法接受另一个 `Vector` 对象作为参数，并返回一个新的 `Vector` 对象，表示两个向量的和。
4. 提供一个公共方法 `print`，用于打印向量的分量。
5. 提供一个方法 `dir`，求取向量的模长并打印。
6. 运行程序时：输入四个值，分别为两个向量的 xy 坐标，输出两向量和的模长。
### C++ 示例
**输入**：
```shell
./vector_add 1 2 3 4
```
**输出**：
```shell
向量之和: x=4, y=6
模长: 7.2111
```
*/
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Vector
{
private:
    double x;
    double y; 
