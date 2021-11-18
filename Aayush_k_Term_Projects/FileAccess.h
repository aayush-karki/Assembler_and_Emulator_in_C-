///
///		File access to source file.
///
#ifndef _FILEACCESS_H  // This is the way that multiple inclusions are defended against often used in UNIX
#define _FILEACCESS_H // We use pragmas in Visual Studio.  See other include files

#include <fstream>

#include "Errors.h"

class FileAccess {

public:

    /// 
    /// @brief constructor, Opens the file.
    ///
    /// @param argc: number of arguments passed. should always be 2 if not error
    /// @param argv: character array with argument passed to the program.
    ///              first element is the binary of the program
    ///              second is the file to be compiled
    /// 
    FileAccess( int argc, char *argv[] );

    /// 
    /// @bried deconstructor, Closes the file.
    ///
    ~FileAccess( );

    /// 
    /// @brief GetNextLine gets the next line from the source file.  
    /// 
    /// @param a_line is the string where the extracted line is stored
    /// 
    /// @returns true if there was one.
    bool GetNextLine( std::string &a_line );

    /// 
    /// @brief Rewind Put the file pointer back to the beginning of the file.
    /// 
    void Rewind( );

    /// 
    ///  @brief CheckEOF checks if the file pointer is currently at end of file
    /// 
    /// returns true if file pointer is pointed at end of file
    inline bool CheckEOF()
    {
        return m_sfile.eof();
    }

private:

    std::ifstream m_sfile;		// Source file object.
};
#endif

