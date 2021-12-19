
// Header
#include "Extension.h"

// Library includes

// Project includes
#include "base64_decode.h"
#include "base64_encode.h"

// Namespace declarations


namespace base64 {


Extension::Extension()
: AExtension( "base64", "0.0.0" )
{
	mName = "base64 (using base64 2.rc.08)";
}

void Extension::initialize( Slang::IScope* scope )
{
	//std::cout << "Extension::initialize()" << std::endl;

	(void)scope;
}

void Extension::provideMethods( Slang::Extensions::ExtensionMethods& methods )
{
	assert( methods.empty() );

    methods.push_back( new base64_decode() );
	methods.push_back( new base64_encode() );
}


}


extern "C" Slang::Extensions::AExtension* factory( void ) {
	return dynamic_cast<Slang::Extensions::AExtension*>( new base64::Extension() );
}

