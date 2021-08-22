#include <stack>
#include "header.h"

string simplifyPath_r(string path)
{
    int phase_begin = 0;
    std::stack<string> files;

    int i = 0;
    while (i < path.length())
    {
        if (path[i] == '/')
        {
            if (i > phase_begin)
            {
                if (i > phase_begin + 1)
                {
                    string phase = path.substr(phase_begin + 1, i - phase_begin - 1);
                    if (phase == ".")
                    {
                        // Do nothing
                    }
                    else if (phase == "..")
                    {
                        if (!files.empty())
                        {
                            files.pop();
                        }
                    }
                    else
                    {
                        files.push(phase);
                    }
                }

                phase_begin = i;
            }
        }
        ++i;
    }

    // Last phase
    if (i > phase_begin + 1)
    {
        string phase = path.substr(phase_begin + 1, i - phase_begin -1);
        if (phase == ".")
        {
            // Do nothing
        }
        else if (phase == "..")
        {
            if (!files.empty())
            {
                files.pop();
            }
        }
        else
        {
            files.push(phase);
        }
    }

    string result;
    while (!files.empty())
    {
        result = "/" + files.top() + result;
        files.pop();
    }

    if (result.length() == 0)
    {
        return "/";
    }
    else
    {
        return result;
    }
}