#ifndef __SQLPARSER__SQLPARSER_H__
#define __SQLPARSER__SQLPARSER_H__

#include "SQLParserResult.h"
#include "sql/statements.h"

namespace hsql {

  // Static methods used to parse SQL strings.
  class SQLParser {
   public:
    // Parses a given constant character SQL string into the result object.
    // Returns true if the lexer and parser could run without internal errors.
    // This does NOT mean that the SQL string was valid SQL. To check that
    // you need to check result->isValid();
    static bool parseSQLString(const char* sql, SQLParserResult* result);

    // Parses a given SQL string into the result object.
    static bool parseSQLString(const std::string& sql, SQLParserResult* result);

    // Deprecated:
    // Parses a given constant character SQL string.
    // Note: This is kept for legacy reasons. It is recommended to use
    //       the (const char*, SQLParserResult*) implementation.
    static SQLParserResult* parseSQLString(const char* sql);

    // Deprecated:
    // Parses an SQL std::string.
    // Note: This is kept for legacy reasons. It is recommended to use
    //       the (const std::string&, SQLParserResult*) implementation.
    static SQLParserResult* parseSQLString(const std::string& sql);

   private:
    // Static class can't be instatiated.
    SQLParser();
  };


} // namespace hsql


#endif