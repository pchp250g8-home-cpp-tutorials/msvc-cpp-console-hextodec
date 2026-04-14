// HexToDec.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <regex>
#include <math.h>

int main(int argc, char* argv[])
{
    const unsigned int nMaxHexDigits = static_cast<unsigned int>(ceil(log2(UINT32_MAX) / 4));
    const std::regex oRegEx("^[0-9A-Fa-f]+$");
    long long nHexPower = 1L;
    long long nDecNum = 0L;
    std::string strLine;
    system("cls");
    std::cout << "Input a hexadecimal number\r\n";
    std::getline(std::cin, strLine);
    unsigned int nStrLen = static_cast<unsigned int>(strLine.length());
    bool bIsRightString = (nStrLen <= nMaxHexDigits) && (std::regex_match(strLine, oRegEx));
    if (!bIsRightString)
    {
        std::cout << "Wrong hexadecimal number format!!!\r\n";
        std::cin.get();
        return 0;
    }
    for (unsigned int i = 0; i < nStrLen; i++)
    {
        unsigned int nHexDigit = 0;
        char chHexDigit = strLine[nStrLen - 1 - i];
        if (chHexDigit >= '0' && chHexDigit <= '9')
            nHexDigit = chHexDigit - '0';
        else if (chHexDigit >= 'A' && chHexDigit <= 'F')
            nHexDigit = 10 + chHexDigit - 'A';
        else if (chHexDigit >= 'a' && chHexDigit <= 'f')
            nHexDigit = 10 + chHexDigit - 'a';
        nDecNum += (nHexDigit * nHexPower);
        nHexPower *= 16;
    }
    std::cout << "The decimal equavalent of the hexadecimal number "
              << strLine << " is: " << nDecNum << "\r\n";
    std::cin.get();
    return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file