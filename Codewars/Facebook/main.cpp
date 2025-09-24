/* * * * * * * * * * * * *
 *                       *
 *                       *
 * Bruh i'm just flexin  *
 *       ヽ( •_)ᕗ        *
 *                       *
 * * * * * * * * * * * * */ 

#include <iostream>
#include <string>
#include <vector>

// std::string likes(const std::vector<std::string> &names)
// {
//     std::string result = "no one likes this";
//     if (names.empty()) return result;
//     if (names.size() == 1) result = names[0];
//     if (names.size() == 2) result = names[0] + " and " + names[1];
//     if (names.size() == 3) result = names[0] + ", " + names[1] + " and " + names[2];
//     if (names.size() > 3) result = names[0] + ", " + names[1] + " and " + std::to_string(names.size() - 2) + " others";

//     return result += " like this"; // Do your magic!
// }

std::string likes(const std::vector<std::string> &names)
{
    std::string result = "";
    switch (names.size())
    {
    case 0: return "no one likes this";
    case 1: return names[0] + " likes this";
    case 2: return names[0] + " and " + names[1] + " like this";
    case 3: return names[0] + ", " + names[1] + " and " + names[2] + " like this";;
    default: return names[0] + ", " + names[1] + " and " + std::to_string(names.size() - 2) + " others like this";
    }
}


int main() {
    std::vector<std::string> names;
    std::vector<std::string> names1 = { "Miles" };
    std::vector<std::string> names2 = { "Jacob", "Alex" };
    std::vector<std::string> names3 = { "Max", "John", "Mark" };
    std::vector<std::string> names4 = { "Alex", "Mike", "Jason", "Tony" };

    std::cout << likes(names) << std::endl;
    std::cout << likes(names1) << std::endl;
    std::cout << likes(names2) << std::endl;
    std::cout << likes(names3) << std::endl;
    std::cout << likes(names4) << std::endl;
    

    return 0;
}