
#ifndef Slang_Base64_base64_decode_h
#define Slang_Base64_base64_decode_h


// Library includes
#include <base64.hpp>

// Project includes
#include <Core/Designtime/BuildInTypes/BoolObject.h>
#include <Core/Designtime/BuildInTypes/StringObject.h>
#include "Defines.h"
#include "Types.h"

// Forward declarations

// Namespace declarations
using namespace Slang;


namespace base64 {


class base64_decode : public Extensions::ExtensionMethod
{
public:
    base64_decode( IScope* parent = nullptr )
	: ExtensionMethod( parent, "base64_decode", Designtime::StringObject::TYPENAME )
	{
		ParameterList params;
		params.push_back( Parameter::CreateDesigntime( "code", Designtime::StringObject::TYPENAME ) );
        params.push_back( Parameter::CreateDesigntime( "removeLinebreaks", Designtime::BoolObject::TYPENAME, Slang::Runtime::AtomicValue( false ), true ) );

		setSignature( params );
	}

public:
	Runtime::ControlFlow::E execute( Common::ThreadId threadId, const ParameterList& params, Runtime::Object* result, const Token& token )
	{
		ParameterList list = mergeParameters( params );

		try {
			ParameterList::const_iterator it = list.begin();

            auto param_code = (*it++).value().toStdString();
			auto param_remove = (*it++).value().toBool();

			*result = Runtime::StringObject( ::base64_decode( param_code, param_remove ) );
		}
		catch ( std::exception& e ) {
            Runtime::Object *data = Controller::Instance().repository()->createInstance( Runtime::StringObject::TYPENAME, ANONYMOUS_OBJECT );
            *data = Runtime::StringObject( std::string( e.what() ) );

            Controller::Instance().thread( threadId )->exception() = Runtime::ExceptionData( data, token.position() );
            return Runtime::ControlFlow::Throw;
		}

		return Runtime::ControlFlow::Normal;
	}
};


}


#endif
