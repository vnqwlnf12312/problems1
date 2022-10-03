#include <cmath>
#include <iomanip>
#include <iostream>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n;
  std::cin >> n;
  long double* segment = new long double[n + 1];
  long double cur;
  segment[0] = 0;
  for (int i = 1; i <= n; ++i) {
    std::cin >> cur;
    segment[i] = segment[i - 1] + log(cur);
  }
  int q;
  int i, j;
  std::cin >> q;
  for (int k = 0; k < q; ++k) {
    std::cin >> i >> j;
    long double power = 1.0 / (j - i + 1);
    std::cout << std::setprecision(30)
              << powl(M_E, (segment[j + 1] - segment[i]) * power) << "\n";
  }
  delete[] segment;
  return 0;
}