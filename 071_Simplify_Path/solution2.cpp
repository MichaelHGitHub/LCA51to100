#include "header.h"

// Two pointers
string simplifyPath2(string path)
{
    string result;

    size_t front = 0;
    size_t rear = 0;

    while (front < path.length() - 1)
    {
        rear = path.find('/', front + 1);

        if (rear == path.npos)
        {
            rear = path.length();
        }

        // Skip "//"
        if (rear - front > 1)
        {
            string s = path.substr(front + 1, rear - front - 1);

            // Skip "."
            if (!s.empty() && s != ".")
            {
                // Handle ".."
                if (s == "..")
                {
                    if (!result.empty())
                    {
                        result.erase(result.find_last_of('/'));
                    }
                }
                else
                {
                    result += "/" + s;
                }
            }
        }

        front = rear;
    }

    if (result.empty())
    {
        return "/";
    }
    else
    {
        return result;
    }
}