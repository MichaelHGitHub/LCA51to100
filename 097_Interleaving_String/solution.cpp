#include <map>
#include "header.h"

static bool checkInterleavePhase(map<vector<char*>, bool>& history, string& s1, int pos1, string& s2, int pos2, string& s3, int pos3);


// Check strings phase by phase(start with longest match of letters, if doesn't work,
// deduct one char and try again. 
// Use a recurrsive helper so that it is easy to check s1 and s2 alternately.
// Use a map to tract the checking history so that we don't do deplicate work.
// The key should be a combination of (str1:pos1, str2:pos2) so that we can 
// uniquely identify the progress of both string. 
// Since nothing is better than the pointer to a char 
// in the string for identifying the string and its pos, we use (char*, char*) as key. 
bool isInterleave(string s1, string s2, string s3)
{
    map<vector<char*>, bool> history;
    // Check s1 first.
    if (checkInterleavePhase(history, s1, 0, s2, 0, s3, 0))
    {
        return true;
    }

    // If starting with s1 doesn't work, try stating with s2
    if (checkInterleavePhase(history, s2, 0, s1, 0, s3, 0))
    {
        return true;
    }

    return false;
}

bool checkInterleavePhase(map<vector<char*>, bool>& history, string& s1, int pos1, string& s2, int pos2, string& s3, int pos3)
{
    // If reach the end of all string, we've found the match.
    if (pos1 == s1.length() && pos2 == s2.length() && pos3 == s3.length())
    {
        return true;
    }

    // Or if s3 is finished and others not, not match.
    if (pos3 == s3.length())
    {
        return false;
    }

    // Check a phase, start with longest match
    int i = pos3;
    int j = pos1;
    while (i < s3.length() && j < s1.length())
    {
        if (s3[i] == s1[j])
        {
            ++i;
            ++j;
        }
        else
        {
            break;
        }
    }

    // The current phase no match at all, the strings don't match.
    if (i == pos3 && j == pos1)
    {
        return false;
    }

    // Check history if from the current postion(next phase) to end has been checked before. 
    // Note: s2 goes first in next phase
    vector<char*>  key(2, 0);
    key[0] = &(s2[pos2]);
    key[1] = &(s1[j]);

    // If it is checked before, just retrived the result instead of doing it again.
    if (history.find(key) != history.end())
    {
        return history[key];
    }

    // Check if from current postitions(next phase) to the end match, and save the result
    // Note: s2 goes first in next phase
    if (checkInterleavePhase(history, s2, pos2, s1, j, s3, i))
    {
        history[key] = true;
        return true;
    }

    history[key] = false;

    // For the current phase, longest match doesn't work, let's try shorter matches
    // each time is one char shorter.
    while (i > pos3 && j > pos1)
    {
        if (checkInterleavePhase(history, s2, pos2, s1, --j, s3, --i))
        {
            return true;
        }
    }

    return false;
}