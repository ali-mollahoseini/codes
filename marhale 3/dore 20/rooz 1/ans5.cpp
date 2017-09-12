#include <bits/stdc++.h>
#define FR(i,n) for(int i=0; i<n; i++)
using namespace std;

typedef long long LL;
enum MatchResult { WIN = 0, DRAW, LOSE };

const int ranki[] = {7, 13, 21, 30};
const int n = 4;
const int nm = n*(n-1)/2 ;// number of matches: 6
const int me = 2; // team 2 is our team
const int delta = 10979;

struct Match {
  int a, b;
  Match(int a, int b) : a(a), b(b) {}
  double p[3]; // based on team a
};

int main() {
  Match mat[] = {Match(0,1), Match(0,2), Match(0,3),
                Match(1,2), Match(1,3), Match(2,3)};
  FR(i,nm) {
    int ra = ranki[mat[i].a], rb = ranki[mat[i].b];
    mat[i].p[DRAW] = (50 - abs(ra - rb)) / double(100);
    mat[i].p[WIN] = rb * (1.0 - mat[i].p[DRAW]) / double(ra + rb);
    mat[i].p[LOSE] = ra * (1.0 - mat[i].p[DRAW]) / double(ra + rb);
  }

  double ans = 0;
  int res[nm];
#define SFR(i) for (res[i]=0; res[i]<=2; res[i]++)
  SFR(0) SFR(1) SFR(2) SFR(3) SFR(4) SFR(5) {
    double prob = 1;
    FR(i,nm) prob *= mat[i].p[res[i]];

    int score[n];
    FR(i,n) score[i] = 0;
    FR(i, nm) {
      if (res[i] == WIN ) { score[mat[i].a] += 3; score[mat[i].b] += 0; }
      if (res[i] == DRAW) { score[mat[i].a] += 1; score[mat[i].b] += 1; }
      if (res[i] == LOSE) { score[mat[i].a] += 0; score[mat[i].b] += 3; }
    }
    int btm = 0; // better than me!
    FR(i,n) if (i != me)
      if (score[i] > score[me] || (score[i] == score[me] && i < me))
        btm++;
    if (btm < 2) ans += prob;
  }
  cout << ans << endl;
  LL final = (LL)((LL)delta*delta*ans);
  cout << final << endl;
  return 0;
}
