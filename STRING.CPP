// STRING.CPP class implementation file

#include "string.hpp"

STRING::STRING( void )
{
    string = NULL;
    buffer = NULL;
}

STRING::STRING( const char& String )
{
    string = (char*)malloc( strlen( &String ) + 1 );
    buffer = NULL;

    if ( string != NULL ) {
        strcpy( string, &String );
    }
}

STRING::STRING( const STRING& String )
{
    string = (char*)malloc( String.Length() + 1 );
    buffer = NULL;

    if ( string != NULL ) {
        strcpy( string, String.GetCharString() );
    }
}

STRING::~STRING( void )
{
	delete[] buffer;
	
    if ( string != NULL ) {
        free( string );
    }
}

char* STRING::GetCharString( void ) const
{
	return string;
}

int STRING::IsEqual( const char* String )
{
    return strcmp( string, String ) == 0 ? 1 : 0;
}

int STRING::IsEqual( const STRING& String )
{
    return strcmp( string, String.GetCharString() ) == 0 ? 1 : 0;
}

unsigned int STRING::Length( void ) const
{
	return (unsigned int)strlen( string );
}

unsigned int STRING::Count( void ) const
{
	return (unsigned int)strlen( string );
}

void STRING::Clear( void )
{
	memset( string, '\0', sizeof( string ) );
}

int STRING::Empty( void )
{
    return string[0] == NULL ? 1 : 0;
}

void STRING::ToUpper( void )
{
	strupr( string );
}

void STRING::ToLower( void )
{
	strlwr( string );
}

char STRING::Back( void )
{
    return string[strlen(string)];
}

char STRING::Front( void )
{
    return string[0];
}

STRING& STRING::SubString( const size_t position, size_t length )
{
	if ( length > strlen( string ) ) {
		length = strlen( string );
	}
	
	buffer = new char[length + 1];
	memset( buffer, '\0', sizeof( buffer ) );
	
	if ( position > strlen( string ) ) {
		return (STRING&)buffer;
	}
	
	memcpy( buffer, &string[position], length );
	buffer[length] = '\0';
	
	return (STRING&)buffer;
}

STRING& STRING::operator=( const char* String )
{
	if ( string == NULL ) {
		string = (char*)malloc( strlen( String ) + 1 );
	}
	else {
		string = (char*)realloc( string, strlen( String ) + 1 );
	}
	
	if ( string != NULL ) {
		strcpy( string, String );
	}
	
    return (STRING&)string;
}

STRING& STRING::operator=( const STRING& String )
{
	if ( string == NULL ) {
		string = (char*)malloc( String.Length() + 1 );
	}
	else {
		string = (char*)realloc( string, String.Length() + 1 );
	}
	
	if ( string != NULL ) {
		strcpy( string, String.GetCharString() );
	}
	
	return (STRING&)string;
}

STRING& STRING::operator+=( const char* String )
{
	string = (char*)realloc( string, strlen( string ) + strlen( String ) + 1 );
	
	if ( string != NULL ) {
		strcat( string, String );
	}
	
	return (STRING&)string;
}

STRING& STRING::operator+=( const STRING& String )
{
	string = (char*)realloc( string, strlen( string ) + String.Length() + 1 );
	
	if ( string != NULL ) {
		strcat( string, String.GetCharString() );
	}
	
	return (STRING&)string;
}

STRING& STRING::operator+( const char* String )
{
	string = (char*)realloc( string, strlen( string ) + strlen( String ) + 1 );
	
	if ( string != NULL ) {
		strcat( string, String );
	}
	
	return (STRING&)string;
}

STRING& STRING::operator+( const STRING& String )
{
	string = (char*)realloc( string, strlen( string ) + String.Length() + 1 );
	
	if ( string != NULL ) {
		strcat( string, String.GetCharString() );
	}
	
	return (STRING&)string;
}

int STRING::operator==( const char* String )
{
	return strcmp( string, String ) == 0 ? 1 : 0;
}

int STRING::operator==( const STRING& String )
{
	return strcmp( string, String.GetCharString() ) == 0 ? 1 : 0;
}

STRING::operator const char*() const
{
	return string;
}
