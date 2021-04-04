#include "header.h"

//
// Cut the string 3 times into 4 phase
// for each cut, length is 1-3.
// The rest of thing is straight forward.
vector<string> restoreIpAddresses2(string s)
{
    if (s.length() < 4 || s.length() > 12)
    {
        return vector<string>();
    }

    vector<string> ip_set;

    // First cut ( length 1-3)
    for (int i = 1; i <= 3; i++)
    {
        // Sanity check for length to avoid unnessecessary interation
        if (i >= s.length() && i + 9 < s.length())
        {
            continue;
        }

        string p1 = s.substr(0, i);
        if ((p1[0] == '0' && p1.length() > 1) ||
            ((p1.length() == 3 && p1 > "255")))
        {
            continue;
        }

        // Second cut ( length 2-6)
        for (int j = i + 1; j <= i + 3; j++)
        {
            // Sanity check for length to avoid unnessecessary interation
            if (j >= s.length() && j + 6 < s.length())
            {
                continue;
            }
            string p2 = s.substr(i, j - i);
            if ((p2[0] == '0' && p2.length() > 1) ||
                ((p2.length() == 3 && p2 > "255")))
            {
                continue;
            }

            // Third cut ( length 3-9)
            for (int k = j + 1; k <= j + 3; k++)
            {
                // Sanity check for length to avoid unnessecessary interation
                if (k >= s.length() || k + 3 < s.length())
                {
                    continue;
                }

                string p3 = s.substr(j, k - j);
                string p4 = s.substr(k);
                if ((p3[0] == '0' && p3.length() > 1) ||
                    (p4[0] == '0' && p4.length() > 1) ||
                    (p3.length() == 3 && p3 > "255") ||
                    (p4.length() == 3 && p4 > "255"))
                {
                    continue;
                }

                ip_set.push_back(p1 + "." + p2 + "." + p3 + "." + p4);
            }
        }
    }

    return ip_set;

}