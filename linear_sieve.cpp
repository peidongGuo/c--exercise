#include <iostream> // 包含输入输出流库
#include <vector>   // 包含向量库
using namespace std;

const int MAXN = 1000000; // 定义筛选的最大范围
vector<int> primes; // 存储所有找到的质数
bool is_prime[MAXN + 1]; // 布尔数组，用于标记每个数是否为质数

// 线性筛函数，用于筛选出 n 以内的所有质数
void linear_sieve(int n) {
    // 初始化 is_prime 数组，将所有数标记为质数
    fill(is_prime, is_prime + n + 1, true);
    is_prime[0] = is_prime[1] = false; // 0 和 1 不是质数

    // 遍历每个数
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) { // 如果当前数是质数
            primes.push_back(i); // 将其加入质数数组
        }
        // 使用已找到的质数标记合数
        for (int j = 0; j < primes.size() && i * primes[j] <= n; ++j) {
            is_prime[i * primes[j]] = false; // 标记合数
            if (i % primes[j] == 0) { // 如果 i 是 primes[j] 的倍数
                break; // 退出循环，避免重复标记
            }
        }
    }
}

int main() {
    int n; // 定义变量 n，用于存储用户输入的范围
    cout << "Enter the range up to which you want to find prime numbers: "; // 提示用户输入范围
    cin >> n; // 读取用户输入的范围

    linear_sieve(n); // 调用线性筛函数，筛选出 n 以内的质数

    // 输出所有找到的质数
    cout << "Prime numbers up to " << n << " are:" << endl;
    for (int prime : primes) { // 遍历质数数组
        cout << prime << " "; // 输出每个质数
    }
    cout << endl; // 输出换行符

    return 0; // 返回 0，表示程序正常结束
}