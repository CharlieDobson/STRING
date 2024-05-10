# STRING
Custom STRING class.

Early C++ compilers, pre-standardization of the C++ 98 specification, had no support for the C++ Standard Template Library (STL).
These compilers were therefore missing support for an important data type known as std::string, which allows for dynamically resizing
arrays of characters, and methods for determining how many characters are in the array, among many other features.

This custom STRING class was written to ease the use of working with character arrays for these early compilers.  This class has been
tested with Microsoft Visual C++ 1.52, Symantec C++ 7.2, Digital Mars C++ 8.5, and Open Watcom C/C++ version 1.9.
