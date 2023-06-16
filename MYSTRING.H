// STRING.H class defintiion file

#if __DMC__ || __SC__ || __RCC__
#ifndef MYSTRING_H
#define MYSTRING_H 1

#include <stdlib.h>
#include <string.h>
#include <limits.h>

#ifndef BOOL
typedef int BOOL;
#endif
#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE !FALSE
#endif

class STRING
{
    char* _string;

  public:
    STRING( void );
    STRING( char *String );
    STRING( STRING *String );
    ~STRING( void );

    // public variables
    unsigned int Length;
    unsigned int Count;
    unsigned int length;
    unsigned int count;

    // accessors and mutators
    void Set( const char *String );
    void Set( const STRING *String );
    void Set( const STRING String );
    void SetString( const char *String );
    void SetString( const STRING *String );
    void SetString( const STRING String );
    STRING Get( void ) const;
    STRING GetString( void ) const;
    char* GetCharString( void ) const;
    char* GetCharacterString( void ) const;
    STRING Concat( const char *String );
    STRING Concat( const STRING *String );
    STRING Concat( const STRING String );

    // methods
    BOOL IsEqual( const char *String );
    BOOL IsEqual( const STRING *String );
    BOOL IsEqual( const STRING String );
    //unsigned int Length( void ) const;
    //unsigned int Count( void ) const;

  protected:
    STRING operator=( const STRING *String );
    STRING operator=( const char *String );
    STRING operator+( const STRING *String );
    STRING operator+( const char *String );
    BOOL operator==( const STRING *String );
    BOOL operator==( const char *String );
};

#endif // end MYSTRING_H
#endif