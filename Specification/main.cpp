
// Library includes
#include <iostream>

// Project includes
#include <Extension.h>

// Namespace declarations


int main( int argc, const char* argv[] )
{
    std::string compareWith;
    if ( argc > 1 ) {
        compareWith = argv[ 1 ];
    }

    Slang::Extensions::ExtensionNamespace scope( "", nullptr );
    Slang::Extensions::ExtensionMethods methods;

    base64::Extension ext;
    ext.initialize( &scope );
    ext.provideMethods( methods );

    std::list<std::string> results;

    for ( auto it = scope.beginSymbols(); it != scope.endSymbols(); ++it )
    {
        results.push_back( it->second->ToString() );
    }

    for ( auto it = scope.beginMethods(); it != scope.endMethods(); ++it )
    {
        results.push_back( (*it)->ToString() );
    }

    for ( auto* method : methods )
    {
        results.push_back( method->ToString() );
    }

    if ( compareWith.empty() ) {
        for ( const auto& str : results ) {
            std::cout << str << std::endl;
        }

        return 0;
    }

    int32_t found{ 0 };
    for ( const auto& str : results ) {
        if ( str.find( compareWith ) != std::string::npos ) {
            std::cout << str << std::endl;

            found++;
        }
    }

    if ( found ) {
//        std::cout << std::endl;
//        std::cout << "found " << found << " occurrence(s) of " << compareWith << std::endl;
    }
    else {
        std::cout << "no result found for '" << compareWith << "'" << std::endl;
    }
}
