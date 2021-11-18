///
///	Implementation of the symbol table class.  This is the format I want for commenting functions.
///
#include "stdafx.h"
#include "SymTab.h"

void SymbolTable::AddSymbol( const std::string &a_symbol, int a_loc )
{
    // If the symbol is already in the symbol table, record it as multiply defined.
    std::map<std::string, int>::iterator st = m_symbolTable.find( a_symbol );
    if( st != m_symbolTable.end() ) {

        st->second = multiplyDefinedSymbol;
        return;
    }
    // Record a the  location in the symbol table.
    m_symbolTable[a_symbol] = a_loc;
}

void SymbolTable::DisplaySymbolTable()
{
    std::map<std::string, int>::iterator currSymbolIte = m_symbolTable.begin();
    int symIndex = 0;

    std::cout << "Symbol Table:" << std::endl << std::endl;

    // formating the table
    std::cout << std::left;
    std::cout << std::setw( MAX_SYMBOL_LENGTH + 1 ) << "Symbol# "
        << std::setw( MAX_SYMBOL_LENGTH + 1 ) << "Symbol"
        << " Location" << std::endl;

    while (currSymbolIte != m_symbolTable.end())
    {
        std::cout << " " << std::setw( 6 ) << symIndex << "\t    "
            << std::setw( MAX_SYMBOL_LENGTH + 1 ) << currSymbolIte->first
            << " " << currSymbolIte->second << std::endl;
        ++symIndex; 
        currSymbolIte++;
    }

    std::cout << std::setfill('_') << std::setw(50) << " " << std::endl << std::endl;
    std::cout << std::setfill( ' ' );

    std::cout << "Press Enter to Continue" << std::endl;

    std::string enter;
    std::getline( std::cin, enter );

}
