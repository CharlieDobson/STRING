// STRING.CPP class implementation file

#include "string.hpp"

STRING::STRING( void )
{
    string = NULL;
	temp_buffer = NULL;
}

STRING::STRING( const char& String )
{
    string = (char*)calloc( 1, strlen( &String ) + 1 );
	temp_buffer = NULL;

    if ( string != NULL ) {
        strcpy( string, &String );
    }
}

STRING::STRING( const STRING& String )
{
    string = (char*)calloc( 1, String.Length() + 1 );
	temp_buffer = NULL;

    if ( *string != NULL ) {
        strcpy( string, String.ToCharString() );
    }
}

STRING::~STRING( void )
{
	if ( temp_buffer != NULL ) {
		free( temp_buffer );
	}
    if ( string != NULL ) {
        free( string );
    }
}

int STRING::IsEqual( const char* String )
{
    return strcmp( string, String ) == 0 ? 1 : 0;
}

int STRING::IsEqual( const STRING& String )
{
    return strcmp( string, String.ToCharString() ) == 0 ? 1 : 0;
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

int STRING::IsEmpty( void )
{
    return string == NULL ? 1 : 0;
}

void STRING::ToUpper( void )
{
	strupr( string );
}

void STRING::ToLower( void )
{
	strlwr( string );
}

char& STRING::Back( void ) const
{
    return string[strlen( string ) - 1];
}

char& STRING::Front( void ) const
{
    return string[0];
}

STRING& STRING::SubString( const size_t position, size_t length )
{
	if ( length > strlen( string ) ) {
		length = strlen( string );
	}

	temp_buffer == NULL ? temp_buffer = (char*)calloc( 1, length - position + 1 ) : temp_buffer = (char*)realloc( temp_buffer, length - position + 1 );
	memset( temp_buffer, '\0', sizeof( temp_buffer ) );

	if ( position > strlen( string ) ) {
		return (STRING&)temp_buffer;
	}

	strncpy( temp_buffer, &string[position], length );
	
	return (STRING&)temp_buffer;
}

STRING& STRING::Insert( const size_t position, const char* String )
{
    string == NULL ? string = (char*)calloc( 1, strlen( String ) + 1 ) : string = (char*)realloc( string, strlen( string ) + strlen( String ) + 1 );
	temp_buffer == NULL ? temp_buffer = (char*)calloc( 1, strlen( string ) + strlen( String ) + 1 ) : temp_buffer = (char*)realloc( temp_buffer, strlen( string ) + strlen( String ) + 1 );
	memset( temp_buffer, '\0', sizeof( temp_buffer ) );

	if ( string == NULL ) {
		return (STRING&)string;
	}

	if ( position == 0 ) {
		strncpy( temp_buffer, String, strlen( String ) );
		strncat( temp_buffer, string, strlen( string ) );
		strncpy( string, temp_buffer, strlen( temp_buffer ) );
	}
	else if ( position < strlen( string ) ) {
		strncpy( temp_buffer, string, position );
		strncat( temp_buffer, String, strlen( String ) );
		strncat( temp_buffer, &string[position], strlen( string ) - position );
		strncpy( string, temp_buffer, strlen( temp_buffer ) );
	}
	else if ( position >= strlen( string ) ) {
		strcat( string, String );
	}

	return (STRING&)string;
}

STRING& STRING::Insert( const size_t position, STRING& String )
{
    string == NULL ? string = (char*)calloc( 1, String.Length() + 1 ) : string = (char*)realloc( string, strlen( string ) + String.Length() + 1 );
	temp_buffer == NULL ? temp_buffer = (char*)calloc( 1, strlen( string ) + String.Length() + 1 ) : temp_buffer = (char*)realloc( temp_buffer, strlen( string ) + String.Length() + 1 );
	memset( temp_buffer, '\0', sizeof( temp_buffer ) );

	if ( string == NULL ) {
		return (STRING&)string;
	}

	if ( position == 0 ) {
		strncpy( temp_buffer, String.ToCharString(), String.Length() );
		strncat( temp_buffer, string, strlen( string ) );
		strncpy( string, temp_buffer, strlen( temp_buffer ) );
	}
	else if ( position < strlen( string ) ) {
		strncpy( temp_buffer, string, position );
		strncat( temp_buffer, String.ToCharString(), String.Length() );
		strncat( temp_buffer, &string[position], strlen( string ) - position );
		strncpy( string, temp_buffer, strlen( temp_buffer ) );
	}
	else if ( position >= strlen( string ) ) {
		strcat( string, String.ToCharString() );
	}

	return (STRING&)string;
}

STRING& STRING::Remove( const size_t position, size_t length )
{
	if ( string == NULL ) {
		return (STRING&)string;
	}

	if ( position == 0 && length == 0 ) {
		return (STRING&)string;
	}

	if ( position >= strlen( string ) ) {
		return (STRING&)string;
	}

	if ( length > strlen( string ) ) {
		length = strlen( string );
	}

	temp_buffer == NULL ? temp_buffer = (char*)calloc( 1, strlen( string ) + 1 ) : temp_buffer = (char*)realloc( temp_buffer, strlen( string ) + 1 );
	memset( temp_buffer, '\0', sizeof( temp_buffer ) );
	strncpy( temp_buffer, string, strlen( string ) );

	string = (char*)realloc( string, strlen( temp_buffer ) - length - position + 1 );
	memset( string, '\0', strlen( temp_buffer ) - length - position + 1 );

	if ( position == 0 ) {
		strncpy( string, &temp_buffer[length], strlen( temp_buffer ) - length );
	}
	else {
		char* buffer = new char[strlen( &temp_buffer[length] ) - length + 1];
		strncpy( string, temp_buffer, position );
		strncpy( buffer, &temp_buffer[length + 1], strlen( temp_buffer ) - length );
		strcat( string, buffer );
		delete[] buffer;
	}

	return (STRING&)string;
}

char* STRING::ToCharString( void ) const
{
	return string;
}

STRING& STRING::operator=( const char* String )
{
    string == NULL ? string = (char*)calloc( 1, strlen( String ) + 1 ) : string = (char*)realloc( string, strlen( String ) + 1 );
	
	if ( string != NULL ) {
		strcpy( string, String );
	}
	
    return (STRING&)string;
}

STRING& STRING::operator=( const STRING& String )
{
    string == NULL ? string = (char*)calloc( 1, String.Length() + 1 ) : string = (char*)realloc( string, String.Length() + 1 );

	if ( string != NULL ) {
		strcpy( string, String.ToCharString() );
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
		strcat( string, String.ToCharString() );
	}
	
	return (STRING&)string;
}

STRING& STRING::operator+=( const char& Char )
{
	string = (char*)realloc( string, strlen( string ) + 2 );

	if ( string != NULL ) {
		string[strlen( string ) + 1] = Char;
		string[strlen( string ) + 2] = '\0';
	}

	return (STRING&)string;
}

STRING& STRING::operator+( const char* String )
{
	temp_buffer == NULL ? temp_buffer = (char*)calloc( 1, strlen( string ) + strlen( String ) + 1 ) : temp_buffer = (char*)realloc( temp_buffer, strlen( string ) + strlen( String ) + 1 );
	memset( temp_buffer, '\0', sizeof( temp_buffer ) );
	
	if ( temp_buffer != NULL ) {
		strcpy( temp_buffer, string );
		strcat( temp_buffer, String );
	}
	
	return (STRING&)temp_buffer;
}

STRING& STRING::operator+( const STRING& String )
{
	temp_buffer == NULL ? temp_buffer = (char*)calloc( 1, strlen( string ) + String.Length() + 1 ) : temp_buffer = (char*)realloc( temp_buffer, strlen( string ) + String.Length() + 1 );
	memset( temp_buffer, '\0', sizeof( temp_buffer ) );
	
	if ( temp_buffer != NULL ) {
		strcpy( temp_buffer, string );
		strcat( temp_buffer, String.ToCharString() );
	}
	
	return (STRING&)temp_buffer;
}

STRING& STRING::operator+( const char& Char )
{
	temp_buffer == NULL ? temp_buffer = (char*)calloc( 1, strlen( string ) + 2 ) : temp_buffer = (char*)realloc( temp_buffer, strlen( string ) + 2 );
	memset( temp_buffer, '\0', sizeof( temp_buffer ) );
	
	if ( temp_buffer != NULL ) {
		strcpy( temp_buffer, string );
		temp_buffer[strlen( temp_buffer ) + 1] = Char;
		temp_buffer[strlen( temp_buffer ) + 2] = '\0';
	}
	
	return (STRING&)temp_buffer;
}

int STRING::operator==( const char* String )
{
	return strcmp( string, String ) == 0 ? 1 : 0;
}

int STRING::operator==( const STRING& String )
{
	return strcmp( string, String.ToCharString() ) == 0 ? 1 : 0;
}

STRING::operator char*() const
{
	return string;
}
