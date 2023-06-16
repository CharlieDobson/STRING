// MYSTRING.CPP class implementation file

#include "mystring.h"

STRING::STRING( void )
{
    _string = NULL;
    Length = 0;
    Count = Length;
    length = Length;
    count = Length;
}

STRING::STRING( char *String )
{
    SetString( String );
}

STRING::STRING( STRING *String )
{
    Set( String );
}

STRING::~STRING( void )
{
    free( _string );
}

void STRING::Set( const char *String )
{
    SetString( String );
}

void STRING::Set( const STRING *String )
{
    _string = (char*)malloc( String->Length + 1 );
    _string = String->GetCharString();
    Length = strlen( _string );
    Count = Length;
    length = Length;
    count = Length;
}

void STRING::Set( const STRING String )
{
    _string = (char*)malloc( String.Length + 1 );
    _string = String.GetCharString();
    Length = strlen( _string );
    Count = Length;
    length = Length;
    count = Length;
}

void STRING::SetString( const char *String )
{
    _string = (char*)malloc( strlen( String ) + 1 );
    strcpy( _string, String );
    Length = strlen( _string );
    Count = Length;
    length = Length;
    count = Length;
}

void STRING::SetString( const STRING *String )
{
    Set( String );
}

void STRING::SetString( const STRING String )
{
    Set( String );
}

STRING STRING::Get( void ) const
{
    return (STRING)_string;
}

STRING STRING::GetString( void ) const
{
    return (STRING)_string;
}

char* STRING::GetCharString( void ) const
{
    return _string;
}

char* STRING::GetCharacterString( void ) const
{
    return GetCharString();
}

STRING STRING::Concat( const char *String )
{
    _string = (char*)realloc( _string, strlen( _string ) + strlen( String ) + 1 );
    strcat( _string, String );
    Length = strlen( _string );
    Count = Length;
    length = Length;
    count = Length;
    return (STRING)_string;
}

STRING STRING::Concat( const STRING *String )
{
    _string = (char*)realloc( _string, strlen( _string ) + String->Length + 1 );
    strcat( _string, String->GetCharString() );
    Length = strlen( _string );
    Count = Length;
    length = Length;
    count = Length;
    return (STRING)_string;
}

STRING STRING::Concat( const STRING String )
{
    _string = (char*)realloc( _string, strlen( _string ) + String.Length + 1 );
    strcat( _string, String.GetCharString() );
    Length = strlen( _string );
    Count = Length;
    length = Length;
    count = Length;
    return (STRING)_string;
}

BOOL STRING::IsEqual( const char *String )
{
    return strcmp( _string, String ) == 0 ? TRUE : FALSE;
}

BOOL STRING::IsEqual( const STRING *String )
{
    return strcmp( _string, String->GetCharString() ) == 0 ? TRUE : FALSE;
}

BOOL STRING::IsEqual( const STRING String )
{
    return strcmp( _string, String.GetCharString() ) == 0 ? TRUE : FALSE;
}

STRING STRING::operator=( const STRING *String )
{
    SetString( (char*)String );
    return GetString();
}

STRING STRING::operator=( const char *String )
{
    SetString( String );
    return GetString();
}

STRING STRING::operator+( const STRING *String )
{
    Concat( (char*)String );
    return GetString();
}

STRING STRING::operator+( const char *String )
{
    Concat( String );
    return GetString();
}

BOOL STRING::operator==( const STRING *String )
{
    return IsEqual( (char*)String );
}

BOOL STRING::operator==( const char *String )
{
    return IsEqual( String );
}