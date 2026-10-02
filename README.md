# Caesar Cipher CLI

A command-line tool for encrypting and decrypting text files using 
the Caesar cipher — written in C, with no external dependencies.

## Usage

./cipher -e <filename> <shift>   # Encrypt a file
./cipher -d <filename> <shift>   # Decrypt a file

## Example

./cipher -e notes.txt 5
# Creates notes.txt.enc, encrypted with a shift of 5

./cipher -d notes.txt.enc 5
# Creates notes.txt.dec, decrypted back to original content

## How it works

Each letter in the file is shifted forward (encrypt) or backward 
(decrypt) by the given number of positions in the alphabet, wrapping 
around safely for any shift value (including negative or very large 
shifts). Non-letter characters (spaces, punctuation, numbers) are 
left unchanged.

## Features

- Preserves uppercase/lowercase
- Safely handles any integer shift value, including negative and 
  shifts larger than 26
- Automatic output file naming (.enc / .dec)
- Proper error handling for missing files, invalid arguments
- Cleans up partial output files on invalid input

## Known limitations

- Invalid shift values (e.g. passing "abc" instead of a number) 
  currently default to shift=0 rather than erroring — Will fix in future. 

## Building

gcc cipher.c -o cipher
