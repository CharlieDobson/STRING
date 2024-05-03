// STRING.HPP class definition file

#pragma warning( disable : 4091 )

#ifndef STRING_HPP
#define STRING_HPP

#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <memory.h>


class STRING
{
    char* string;
    char* buffer;

  public:
    STRING( void );
    STRING( const char& String );
    STRING( const STRING& String );
    ~STRING( void );

    // accessors and mutators
    char* GetCharString( void ) const;

    // methods
    unsigned int Length( void ) const;
    unsigned int Count( void ) const;
    void Empty( void );
    void ToUpper( void );
    void ToLower( void );
    STRING& SubString( const size_t position, size_t length );

    // operator overloads
    STRING& operator=( const char* String );
    STRING& operator=( const STRING& String );
    STRING& operator+=( const char* String );
    STRING& operator+=( const STRING& String );
    STRING& operator+( const char* String );
    STRING& operator+( const STRING& String );
    int operator==( const char* String );
    int operator==( const STRING& String );
    operator const char*() const;
    
  protected:
    int IsEqual( const char* String );
    int IsEqual( const STRING& String );
};

#pragma warning( default : 4091 )

#endif // end STRING_HPP