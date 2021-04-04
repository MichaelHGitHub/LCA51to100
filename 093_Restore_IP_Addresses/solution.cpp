#include "header.h"

static bool helper(vector<string>& ip_set, string& ip, string s, int start, int phrase);

// Recursive back track.
// Kind of duplication check, but the total valid length is only 12. not 
// a big deal, and run time speed beat 100%. Cool. 
vector<string> restoreIpAddresses(string s)
{
    if (s.length() < 4 || s.length() > 12)
    {
        return vector<string>();
    }

    vector<string> ip_set;
    string ip;

    helper(ip_set, ip, s, 0, 0);

    return ip_set;

}

bool helper(vector<string>& ip_set, string& ip, string s, int start, int phase)
{
    if (phase == 4 && start == s.length())
    {
        // Erease the tailing '.';
        ip.erase(ip.length() - 1, 1);
        return true;
    }

    if (phase > 4 || start > s.length())
    {
        return false;
    }

    size_t len = ip.length();


    ip.append(s.substr(start, 1) + ".");
    if (helper(ip_set, ip, s, start + 1, phase + 1))
    {
        ip_set.push_back(ip);

        // '.' is already ereased when return true from underneath
        ip.erase(len, 1);
    }
    else
    {
        ip.erase(len, 2);
    }


    if (start < s.length() - 1 &&
        s[start] != '0')
    {
        ip.append(s.substr(start, 2) + ".");
        if (helper(ip_set, ip, s, start + 2, phase + 1))
        {
            ip_set.push_back(ip);
            ip.erase(len, 2);
        }
        else
        {
            ip.erase(len, 3);
        }
    }

    if (start < s.length() - 2 &&
        s[start] != '0' &&
        s.substr(start, 3) <= "255")
    {
        ip.append(s.substr(start, 3) + ".");
        if (helper(ip_set, ip, s, start + 3, phase + 1))
        {
            ip_set.push_back(ip);
            ip.erase(len, 3);
        }
        else
        {
            ip.erase(len, 4);
        }
    }

    return false;
}