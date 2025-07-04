
// Header
#include "Extension.h"

// Library includes
#include <cassert>
#include <iostream>

// Project includes
#include "base64_decode.h"
#include "base64_encode.h"

// Namespace declarations

namespace base64 {

Extension::Extension()
: AExtension( "extBase64", "0.2.0" )
{
    mName = "extBase64 (using base64 2.rc.09)";
}

void Extension::initialize( Slang::Extensions::ExtensionNamespace *scope )
{
    (void) scope;

    //auto* decode = new base64_decode( scope );
    //auto* encode = new base64_encode( scope );

    //scope->defineMethod( decode->getName(), decode );
    //scope->defineMethod( encode->getName(), encode );
}

void Extension::provideMethods( Slang::Extensions::ExtensionMethods &methods )
{
    assert( methods.empty() );

    methods.push_back( new base64_decode() );
    methods.push_back( new base64_encode() );
}

} // namespace base64

extern "C" Slang::Extensions::AExtension *factory(void)
{
    return dynamic_cast<Slang::Extensions::AExtension *>( new base64::Extension() );
}
