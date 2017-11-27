// Copyright (C) 2016 Sayutin Dmitry.
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; version 3

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; If not, see <http://www.gnu.org/licenses/>.


#include <iostream>
#include <vector>
#include <stdint.h>
#include <algorithm>
#include <set>
#include <map>
#include <array>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#include <string>
#include <assert.h>
#include <iterator>

using std::cin;
using std::cout;
using std::cerr;

using std::vector;
using std::map;
using std::array;
using std::set;
using std::string;

using std::pair;
using std::make_pair;

using std::min;
using std::abs;
using std::max;

using std::sort;
using std::generate;
using std::min_element;
using std::max_element;

template <typename T>
T input() {
    T res;
    cin >> res;
    return res;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t n, m;
    cin >> n >> m;

    size_t len1 = 1, len2 = 1;
    for (size_t a = 7; a < n; a *= 7)
        len1 += 1;
    for (size_t b = 7; b < m; b *= 7)
        len2 += 1;

    size_t ans = 0;
    if (len1 + len2 <= 7)
        for (size_t i = 0; i != n; ++i)
            for (size_t j = 0; j != m; ++j) {
                vector<size_t> used(7, 0);

                for (size_t a = i, k = 0; k != len1; a /= 7, ++k)
                    used[a % 7] += 1;
                for (size_t b = j, k = 0; k != len2; b /= 7, ++k)
                    used[b % 7] += 1;

                if (*std::max_element(used.begin(), used.end()) <= 1)
                    ++ans;
            }

    cout << ans << "\n";

    return 0;
}
