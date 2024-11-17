#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// 函数声明
double **inv(double **a, int n);

int main() 
{
    int n;
    cin >> n;

    // 动态分配二维数组 a
    double **a = new double *[n];
    for (int i = 0; i < n; ++i) 
    {
        a[i] = new double[n];
    }

    // 输入矩阵 a
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            cin >> a[i][j];
            while (cin.fail()) 
            {
                cin.clear();
                cin.ignore(1024, '\n');
                cout << "输入不合法，请重新输入（任意实数包括负数）：";
                cin >> a[i][j];
            }
        }
    }

    // 计算逆矩阵
    double **b = inv(a, n);
    if (!b) {
        cout << "逆矩阵不存在!\n";
        return 0;
    }

    // 输出逆矩阵
    cout << fixed << setprecision(6);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(10) << b[i][j] << " ";
        }
        cout << endl;
    }

    // 释放动态分配的内存
    for (int i = 0; i < n; ++i) {
        delete[] a[i];
        delete[] b[i];
    }
    delete[] a;
    delete[] b;

    return 0;
}

// 计算矩阵的逆矩阵
double **inv(double **a, int n) {
    unsigned char i, j, k = -1;
    double **t = new double *[n], **b = new double *[n]; // t作为逆矩阵，b作为原矩阵的副本
    // 拷贝a并把t初始化为单位矩阵
    for (i = 0; i < n; ++i) {
        t[i] = new double[n];
        b[i] = new double[n];
        for (j = 0; j < n; ++j) {
            b[i][j] = a[i][j];
            if (i == j)
                t[i][j] = 1.;
            else
                t[i][j] = 0.;
        }
    }
    double x;
    double *w;
    while (++k < n) { // 化原矩阵为阶梯型
        // 第k行第k列为零，在第k列中寻找不为零的元素
        if (abs(b[k][k]) < 1e-5) {
            i = k;
            while (++i < n && abs(b[i][k]) < 1e-5);
            if (i == n) {
                for (i = 0; i < n; ++i) {
                    delete[] t[i];
                    delete[] b[i];
                }
                delete[] t;
                delete[] b;
                return nullptr;
            }
            w = b[k];
            b[k] = b[i];
            b[i] = w;
            w = t[k];
            t[k] = t[i];
            t[i] = w;
        }
        for (j = k + 1; j < n; ++j) {
            x = b[j][k] / b[k][k];
            for (i = k; i < n; ++i)
                b[j][i] -= b[k][i] * x;
            for (i = 0; i < n; ++i)
                t[j][i] -= t[k][i] * x;
        }
    }
    for (i = 0; i < n; ++i) { // 化阶梯型为单位矩阵
        x = b[i][i];
        for (j = 0; j < n; ++j) {
            b[i][j] /= x;
            t[i][j] /= x;
        }
    }
    for (i = n; i--;) {
        for (j = i; j--;) {
            x = b[j][i];
            for (k = 0; k < n; ++k) {
                b[j][k] -= b[i][k] * x;
                t[j][k] -= t[i][k] * x;
            }
        }
    }
    for (i = 0; i < n; ++i)
        delete[] b[i];
    delete[] b;
    return t;
}