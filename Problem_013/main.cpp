#include <iostream>

int string_distinct_char(std::string string)
{
    std::string distinct_char = "";
    for(int i = 0; i < string.length(); i++)
    {
        if(distinct_char.find(string.at(i)) == std::string::npos)
        {
            distinct_char += string.at(i);
        }
    }

    return distinct_char.length();
}

//Get longest substring 
// @param s original string
// @param k max distinct characters in subtring
std::string longest_substring(std::string s, int k)
{
    std::string longestSubstring = "";
    std::string currentSubstring = "";

    for(int i = 0; i < s.length(); i ++)
    {
        
        if(currentSubstring.find(s.at(i)) == std::string::npos)
        {
            if(string_distinct_char(currentSubstring) == k)
            {
                if(longestSubstring.length() < currentSubstring.length())
                    longestSubstring = currentSubstring;
                
                
                currentSubstring = currentSubstring.substr(currentSubstring.find_last_of(currentSubstring.at(0)) + 1);
            }
        }

        currentSubstring += s.at(i);
    }

    if(currentSubstring.length() > longestSubstring.length())
        longestSubstring = currentSubstring;

    return longestSubstring;
}

int main()
{
    std::cout<<"Daily Coding Problem 13"<<std::endl;

    std::cout<<longest_substring("abcbbdca", 3)<<std::endl;

    return 0;
}