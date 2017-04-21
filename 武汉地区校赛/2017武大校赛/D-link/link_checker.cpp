#include "testlib.h"
#include <cmath>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

const double EPS = 1E-4;

int main(int argc, char * argv[])
{
    setName("yes no and then compare two sequences of doubles, max absolute or relative error = %.5f", EPS);
    registerTestlibCmd(argc, argv);

    const string YES = "YES";
    const string NO = "NO";

    int n = 0;
    double j = 0, p = 0;
    double maxerror = 0;

    while (!ans.seekEof())
    {
        n++;
        std::string ja = upperCase(ans.readWord());
        std::string pa = upperCase(ouf.readWord());
        if (ja != YES && ja != NO) quitf(_fail, "answer is illegal");
        if (pa != YES && pa != NO)
			quitf(_wa, "YES or NO expected, but %s found", compress(pa).c_str());
        if (ja != pa)
			quitf(_wa, "expected %s, found %s on %d%s line", compress(ja).c_str(), compress(pa).c_str(), n, englishEnding(n).c_str());
        if (pa == YES && ja == YES) continue;
        j = ans.readDouble();
        p = ouf.readDouble();
        if (!doubleCompare(j, p, EPS))
        {
            quitf(_wa, "first numbers of %d%s line differ - expected: '%.5f', found: '%.5f', error = '%.5f'",
                n, englishEnding(n).c_str(), j, p, doubleDelta(j, p));
        }
        maxerror = max(maxerror, doubleDelta(j, p));
        j = ans.readDouble();
        p = ouf.readDouble();
        if (!doubleCompare(j, p, EPS))
        {
            quitf(_wa, "second numbers of %d%s line differ - expected: '%.5f', found: '%.5f', error = '%.5f'",
                n, englishEnding(n).c_str(), j, p, doubleDelta(j, p));
        }
        maxerror = max(maxerror, doubleDelta(j, p));
    }
    quitf(_ok, "%d lines, max delta is '%.5f'", n, maxerror);
}
