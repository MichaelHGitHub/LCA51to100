#include "header.h"

bool getIp(vector<string>& results, string& ip, int phase, string s, int pos);

vector<string> restoreIpAddresses_r(string s)
{
    vector<string> results;
    string ip;
    getIp(results, ip, 1, s, 0);

    return results;
}

bool getIp(vector<string>& results, string& ip, int phase, string s, int pos)
{
    if (phase == 5 && pos == s.length())
    {
        results.push_back(ip);
        return true;
    }
    else if (phase > 5 || pos > s.length())
    {
        return false;
    }

    for (int i = 1; i <= 3; i++)
    {
        if (i > s.length() - pos)
        {
            return false;
        }

        if (i > 1 && s[pos] == '0')
        {
            return false;
        }

        string sub = s.substr(pos, i);
        if (i == 3 && sub > "255")
        {
            return false;
        }

        size_t pos_in_ip = ip.length();

        if (phase > 1)
        {
            ip.append(".");
        }
        ip.append(sub);

        getIp(results, ip, phase + 1, s, pos + i);
        ip.erase(pos_in_ip);
    }
    return true;
}