// STRING.HPP class definition file

#ifndef STRING_HPP
#define STRING_HPP

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <memory.h>
#include <iostream.h>


class STRING
{
    char* string;
    char* temp_buffer;

  public:
    STRING( void );
    STRING( const char* String );
    STRING( const STRING& String );
    ~STRING( void );

    // accessors, mutators and methods
    unsigned int Length( void ) const;
    unsigned int Count( void ) const;
    void Clear( void );
    int IsEmpty( void );
    void ToUpper( void );
    void ToLower( void );
    char& Back( void ) const;
    char& Front( void ) const;
    STRING& SubString( const size_t position, size_t length );
    STRING& Insert( const size_t position, const char* String );
    STRING& Insert( const size_t position, STRING& String );
    STRING& Remove( const size_t position, size_t length );
    char* ToCharString( void ) const;

    // operator overloads
    STRING& operator=( const char* String );
    STRING& operator=( const STRING& String );
    STRING& operator+=( const char* String );
    STRING& operator+=( const STRING& String );
    STRING& operator+=( const char& Char );
    STRING& operator+( const char* String );
    STRING& operator+( const STRING& String );
    STRING& operator+( const char& Char );
    int operator==( const char* String );
    int operator==( const STRING& String );
    operator char*() const;

  protected:
    int IsEqual( const char* String );
    int IsEqual( const STRING& String );
};

#endif // end STRING_HPP