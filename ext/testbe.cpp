#include <stdio.h>

#include "DirectXMathBE.h"

using namespace DirectX;

void printvector( const char *str, FXMVECTOR V )
{
#ifdef _M_ARM
    printf("%S %f %f %f %f\n\t(%08X %08X %08X %08X)\n", str, V.n128_f32[0], V.n128_f32[1], V.n128_f32[2], V.n128_f32[3],
                                                          V.n128_u32[0], V.n128_u32[1], V.n128_u32[2], V.n128_u32[3] );
#else
    auto* u = reinterpret_cast<const uint32_t*>(&V);
    auto* f = reinterpret_cast<const float*>(&V);
    
    printf("%s %f %f %f %f\n\t(%08X %08X %08X %08X)\n", str, f[0], f[1], f[2], f[3], u[0], u[1], u[2], u[3] );
#endif
}

static const XMVECTORF32 V1 = { 0.1f, 0.2f, 0.3f, 0.4f };
static const XMVECTORF32 V2 = { 1.1f, 1.2f, 1.3f, 1.4f };
static const XMVECTORF32 V3 = { 2.1f, 2.2f, 2.3f, 2.4f };

int main()
{
    if ( XMVerifyCPUSupport() )
    {
        printf("CPU supported for SSE/SSE2\n");

        XMVECTOR BE = XMVectorEndian( V1 );
        printvector( "V1", V1 );
        printvector( "BE", BE );
 
        XMVECTOR LE = XMVectorEndian( BE );
        printvector( "LE", LE );
    }

#ifndef _M_ARM
    if ( SSSE3::XMVerifySSSE3Support() )
    {
        printf("SSSE3 supported\n");

        XMVECTOR BE = SSSE3::XMVectorEndian( V1 );
        printvector( "V1", V1 );
        printvector( "BE", BE );
 
        XMVECTOR LE = SSSE3::XMVectorEndian( BE );
        printvector( "LE", LE );
    }
#endif

    return 0;
}