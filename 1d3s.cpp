#include <iostream>
#include <fstream>
#include <string>
#include <cassert>


const int ALPHABET_LENGTH{26};

int number_from_letter(char letter) {
  int offset = letter - (int)'a';
  if (offset < 0 || offset >= ALPHABET_LENGTH) {
    std::cout << "number_from_letter called with invalid argument (" << letter << ").\n";
    assert(false);
  }
  return offset;
}

char letter_from_number(int number) {

  if (number < 0 || number >= ALPHABET_LENGTH) {
    std::cout << "letter_from_number called with an invalid argument (" << number << ").\n";
    assert(false);
  }

  const char alphabet[] = { 'a',
    'b',
    'c',
    'd',
    'e',
    'f',
    'g',
    'h',
    'i',
    'j',
    'k',
    'l',
    'm',
    'n',
    'o',
    'p',
    'q',
    'r',
    's',
    't',
    'u',
    'v',
    'w',
    'x',
    'y',
    'z'};
  return alphabet[number];
}

/*
* The target of this program is so that it can encrypt messages 
* The code that is ran reads in a file that starts with a shift direction that is either 'l' or 'r'.
* After that, the shift number is read from the file and stored in shift_number. If no shift number is found an error is given and ends the program.
* 
*/
int main() {
    int const alphabet_length = 26;
    int encrypted_position = 0;
    char encrypted = ' ';
    char placeHolder = ' ';
    char plaintext = ' ';
    int plaintext_position = 0;
    int shift_number = 0;
    char shift_direction = ' ';
    
    std::ifstream input_file;
    input_file.open("input.txt");

    input_file >> shift_direction;
    
    if (shift_direction == ' ') {
        std::cout << "Oops: Could not read the direction from the input file." << std::endl;
        return 0;
    }
    else if (shift_direction != 'l' && shift_direction != 'r') {
        std::cout << "Oops: Invalid direction in the input file." << std::endl;
        return 0;
    }

    input_file >> shift_number;
    if (shift_number == 0) {
        std::cout << "Oops: Could not read the shift number from the input file." << std::endl;
        return 0;
    }

    while (!(std::iscntrl(input_file.peek())) && !(input_file.eof())) {
        input_file >> plaintext;
        plaintext_position = number_from_letter(plaintext);
        if (shift_direction == 'l') {
           encrypted_position = plaintext_position - shift_number;
        }
        else {
           encrypted_position = plaintext_position + shift_number;
            }
        encrypted_position %= alphabet_length;
        if (encrypted_position < 0) {
            encrypted_position += alphabet_length;
           }
        encrypted = letter_from_number(encrypted_position);
        std::cout << encrypted;
    }
    std::cout << std::endl;
    
    return 0;





}