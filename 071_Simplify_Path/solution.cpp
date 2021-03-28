#include <stack>
#include "header.h"

string simplifyPath(string path)
{
    stack<string> paths;

    size_t front_start = 0;
    size_t rear_end = 0;

    while (front_start < path.length() - 1)
    {
        rear_end = path.find('/', front_start + 1);

        if (rear_end == path.npos)
        {
            rear_end = path.length();
        }

        if (rear_end - front_start > 1)
        {
            string s = path.substr(front_start + 1, rear_end - front_start - 1);

            if (!s.empty() && s != ".")
            {
                if (s == "..")
                {
                    if (!paths.empty())
                    {
                        paths.pop();
                    }
                }
                else
                {
                    paths.push(s);
                }
            }
        }

        front_start = rear_end;
    }

    string result;
    while (!paths.empty())
    {
        if (result.empty())
        {
            result = paths.top();
        }
        else
        {
            result = paths.top() + "/" + result;
        }

        paths.pop();
    }

    result = "/" + result;

    return result;

}