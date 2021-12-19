
#ifndef Slang_Base64_Extension_h
#define Slang_Base64_Extension_h


// Library includes

// Project includes
#include <Core/Extensions/AExtension.h>
#include "Defines.h"

// Forward declarations

// Namespace declarations


namespace base64 {


class Extension : public Slang::Extensions::AExtension
{
public:
    Extension();
    ~Extension() = default;

public:
    void initialize( Slang::IScope* scope );
    void provideMethods( Slang::Extensions::ExtensionMethods& methods );
};


}


#endif
