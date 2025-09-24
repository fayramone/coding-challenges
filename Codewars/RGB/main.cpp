/* * * * * * * * * * * * *
 *                       *
 *                       *
 * Bruh i'm just flexin  *
 *       ヽ( •_)ᕗ        *
 *                       *
 * * * * * * * * * * * * */ 

#include <iostream>
#include <sstream>
#include <iomanip>

std::string rgb_to_hex(int r, int g, int b)
{
    r = std::clamp(r, 0, 255);
    g = std::clamp(g, 0, 255);
    b = std::clamp(b, 0, 255);

    std::stringstream ss;
    ss << std::hex << std::uppercase << std::setfill('0') 
        << std::setw(2) << r 
        << std::setw(2) << g 
        << std::setw(2) << b;
    
    return ss.str();
}

int main() {
    std::cout << rgb_to_hex(-20, 275, 125);

    return 0;
}