#include <stdio.h>

#include "DirectXMathAVX.h"

using namespace DirectX;

void printvector( const char *str, FXMVECTOR V )
{
    auto* f = reinterpret_cast<const float*>(&V);
    printf("%s %f %f %f %f\n", str, f[0], f[1], f[2], f[3] );
}

static const XMVECTORF32 A = { 1.f, 2.f, 3.f, 4.f };

int main()
{
    if ( XMVerifyCPUSupport() )
    {
        printf("CPU supported for SSE/SSE2\n");

        XMVECTOR V = XMVectorSplatX( A );
        printvector( "A.xxxx", V );

        V = XMVectorSplatY( A );
        printvector( "A.yyyy", V );

        V = XMVectorSplatZ( A );
        printvector( "A.zzzz", V );

        V = XMVectorSplatW( A );
        printvector( "A.wwww", V );
    }

    if ( AVX::XMVerifyAVXSupport() )
    {
        printf("AVX supported\n");

        XMVECTOR V = AVX::XMVectorSplatX( A );
        printvector( "A.xxxx", V );

        V = AVX::XMVectorSplatY( A );
        printvector( "A.yyyy", V );

        V = AVX::XMVectorSplatZ( A );
        printvector( "A.zzzz", V );

        V = AVX::XMVectorSplatW( A );
        printvector( "A.wwww", V );
    }

    return 0;
}