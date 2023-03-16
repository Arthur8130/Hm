#include <iostream>
#include <fstream>
#include <string>
#include <windows.h> 
#include <vector>

//convert text to ASCII and multiply 
unsigned long long convertToASCII(std::string text, int start) 
{
    unsigned long long res = 1;
    for (int i = 0; i < text.length(); i++)
    {
        char x = text.at(i);
        res = res*int(x);
    }
    return res;
}
//count frequency of letters in string and write it out in ASCII
std::string countLetters(std::string text)
{
    std::string res = "";
    int occurence [128];
    for (int i = 0; i < sizeof(occurence) / sizeof(int); i++) occurence[i] = 0;
    for (int i = 0; i < text.length(); i++) 
    {
        char x = text.at(i);
        occurence[int(x)] += 1;
    }
    for (int i = 0; i < sizeof(occurence) / sizeof(int); i++)
        res = res + std::to_string(occurence[i]);
    return res;
}

int main()
{
    int dup1 = 0, dup2 = 0;
    std::vector<unsigned long long> s1;
    std::vector<std::string> s2;
    std::ifstream book;
    std::string str;

    book.open("full.txt");

    if (book.is_open())
        while (book.good())
        {
            char s = book.get();
            str = str + s;
        }
    
    for (int i = 0; i < 500; i++) 
    {
        std::string text;
        int random = rand() % 400000; //book text length - 100
        for (int j = random; j < random + 10; j++) text = text + str.at(j);
        s1.push_back(convertToASCII(text, random));
        s2.push_back(countLetters(text));
    }
    std::vector<unsigned long long> s3;
    for (int i = 0; i < s1.size(); i++) {
        for (int j = i; j < s1.size(); j++) 
            if (s1[i] == s1[j] && i != j) 
            {
                bool state = false;
                for (int k = 0; k < s3.size(); k++)
                    if (s3[k] == s1[i]) state = true;
                if (!state) 
                {
                    s3.push_back(s1[i]);
                    dup2++;
                }
            }
    }
    std::vector<std::string> s4;
    for (int i = 0; i < s2.size(); i++) {
        for (int j = i; j < s2.size(); j++)
        {
            if (s2[i] == s2[j] && i != j) {
                bool state = false;
                for (int k = 0; k < s4.size(); k++)
                    if (s4[k] == s2[i]) state = true;
                if (!state) 
                {
                    s4.push_back(s2[i]);
                    dup2++;
                }
            }
        }
    }
    std::cout << "duplicates in first function = " << dup1 << " in " << s1.size() << " values \n";
    std::cout << "duplicates in second function = " << dup2 << " in " << s2.size() << " values \n";
    std::cout << str.length();
    book.close();
    return 0;
}