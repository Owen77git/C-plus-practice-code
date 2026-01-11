// File: file_encrypt.cpp (50 lines)
#include <iostream>
#include <fstream>
#include <string>

class FileEncryptor {
private:
    std::string key;
    
    char encryptChar(char ch, int position) {
        return ch ^ key[position % key.length()]; // Simple XOR encryption
    }
    
    char decryptChar(char ch, int position) {
        return encryptChar(ch, position); // XOR is symmetric
    }
    
public:
    FileEncryptor(const std::string& k) : key(k) {}
    
    bool encryptFile(const std::string& inputFile, const std::string& outputFile) {
        std::ifstream in(inputFile, std::ios::binary);
        std::ofstream out(outputFile, std::ios::binary);
        
        if (!in || !out) return false;
        
        char ch;
        int position = 0;
        while (in.get(ch)) {
            out.put(encryptChar(ch, position++));
        }
        
        in.close();
        out.close();
        return true;
    }
    
    bool decryptFile(const std::string& inputFile, const std::string& outputFile) {
        return encryptFile(inputFile, outputFile); // Same operation for XOR
    }
};

int main() {
    FileEncryptor encryptor("MySecretKey123");
    
    // First, let's create a test file
    std::ofstream test("test.txt");
    test << "This is a secret message! Don't tell anyone!";
    test.close();
    
    // Encrypt the file
    if (encryptor.encryptFile("test.txt", "encrypted.dat")) {
        std::cout << "File encrypted successfully!\n";
    }
    
    // Decrypt the file
    if (encryptor.decryptFile("encrypted.dat", "decrypted.txt")) {
        std::cout << "File decrypted successfully!\n";
    }
    
    // Display decrypted content
    std::ifstream result("decrypted.txt");
    std::string content;
    getline(result, content);
    std::cout << "Decrypted content: " << content << std::endl;
    
    return 0;
}
