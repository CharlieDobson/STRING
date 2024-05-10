#include "string.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main( int argc, char** argv )
{
    STRING name;
    name = "Joe";
    puts( name );

    name += " Smith";
    puts( name );

    name.Clear();
    puts( name );

    name = "Debra";
    puts( name );
    puts( name.SubString( 1, 3 ) );

    name.ToLower();
    puts( name );

    name.ToUpper();
    puts( name );

    name = "Donna Johnson";
    puts( name );

    STRING name2;
    name2 = name;
    puts( name2 );
    printf( "%c\n", name2.Back() );
    printf( "%c\n", name2.Front() );
    printf( "%i\n", name2.Length() );

    
    return 0;
}
