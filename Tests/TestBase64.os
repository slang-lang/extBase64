#!/usr/bin/env slang

public void Main( int argc, string args ) {
    assert( Test_decode() );
    assert( Test_encode() );
}

private bool Test_decode() {
    print( "TestCase 1: decode" );

    var input = "VGhpcyBpcyBhIHRleHQ=";
    print( input );

    var code = base64_decode( input );
    print( code );

    return code == "This is a text";
}

private bool Test_encode() {
    print( "TestCase 2: encode" );

    var input = "This is a text";
    print( input );

    var code = base64_encode( input );
    print( code );

    return code == "VGhpcyBpcyBhIHRleHQ=";
}
