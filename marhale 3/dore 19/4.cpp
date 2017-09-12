#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000*1000;

vector<int> fibo;

int main() {
  fibo.push_back(2);
  fibo.push_back(3);
  while (true) {
    int n = fibo.size();
    int k = fibo[n-1] + fibo[n-2];
    if (k > MAX) break;
    fibo.push_back(k);
  }

  int all = 0, good = 0;
  for (int i=MAX/10; i<MAX; i++) {
    all++;
    for (int j=0; j<fibo.size() && fibo[j] <= i; j++)
      if (i % fibo[j] == 0)
        goto hell;
    good++;
  hell: ;
  }

  double d = double(good) / all * 100;
  cerr << fixed << setprecision(10) << d*10733 << endl;

  return 0;
}
