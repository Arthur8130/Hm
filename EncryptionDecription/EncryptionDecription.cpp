#include <string>
#include <iostream>

class ViginereCipher {
public:
    std::string key;
    ViginereCipher(std::string key)
    {
        for (int i = 0; i < key.size(); ++i) 
        {
            if (key[i] >= 'A' && key[i] <= 'Z')
                this->key += key[i];
            else if (key[i] >= 'a' && key[i] <= 'z')//makes letter uppercase if it is not
                this->key += key[i] + 'A' - 'a';
        }
    }
    std::string encryption(std::string input) 
    {
        std::string output;
        for (int i = 0, j = 0; i < input.length(); i++)
        {
            char c = input[i];
            if (c >= 'a' && c <= 'z')
                c += 'A' - 'a';
            else if (c < 'A' || c > 'Z')
                continue;
            output += (c + key[j]) % 26 + 'A'; //added 'A' to bring it in range of ASCII alphabet [ 65-90 | A-Z ]
            j = (j + 1) % key.length();
        }
        return output;
    }
    std::string decryption(std::string input) {
        std::string output;
        for (int i = 0, j = 0; i < input.length(); ++i) {
            char c = input[i];
            if (c >= 'a' && c <= 'z')
                c += 'A' - 'a';
            else if (c < 'A' || c > 'Z')
                continue;
            output += (c - key[j]+2*'A') % 26 + 'A';//in case (c - key[j]) gives us negative number "twist" alphabet by adding 2'A' 
            j = (j + 1) % key.length();
        }
        return output;
    }
};
int main() {
    ViginereCipher vig("zlemon");
    std::string ori = "zretreatatdawn";
    std::string encrypt = vig.encryption(ori);
    std::string decrypt = vig.decryption(encrypt);
    std::cout << "Original Message: " << ori << std::endl;
    std::cout << "Encrypted Message: " << encrypt << std::endl;
    std::cout << "Decrypted Message: " << decrypt << std::endl;
    std::cout << int('A' - 'a');
}
