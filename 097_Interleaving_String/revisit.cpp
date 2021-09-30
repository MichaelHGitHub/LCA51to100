#include "header.h"
#include <map>

bool checkInterLeave(
    std::map< pair<int, int>, bool>& history1, 
    std::map< pair<int, int>, bool>& history2, 
    string& s1, int p1, string& s2, int p2, string& s3, int p3);

bool isInterleave_r(string s1, string s2, string s3)
{
    std::map< pair<int, int>, bool> history1;
    std::map< pair<int, int>, bool> history2;

    return checkInterLeave(history1, history2, s1, 0, s2, 0, s3, 0) || 
        checkInterLeave(history2, history1, s2, 0, s1, 0, s3, 0);
}

bool checkInterLeave(
    std::map< pair<int, int>, bool>& history1,
    std::map< pair<int, int>, bool>& history2,
    string& s1, int p1, string& s2, int p2, string& s3, int p3)
{
    if (p1 == s1.length() && p2 == s2.length() && p3 == s3.length())
    {
        return true;
    }

    std::pair<int, int> key(p1, p2);

    if (history1.find(key) != history1.end())
    {
        return history1[key];
    }

    size_t len = s3.length() - p3;
    for (int i = 1; i <= len; i++)
    {
        if (p1 != s1.find(s3.substr(p3, i), p1))
        {
            history1[key] = false;
            return false;
        }

        if (checkInterLeave(history2, history1, s2, p2, s1, p1 + i, s3, p3 + i))
        {
            history1[key] = true;
            return true;
        }
    }

    history1[key] = false;
    return false;
}