#include <stdio.h>

#include "DirectXMathSSE4.h"

using namespace DirectX;

int main()
{
    if ( XMVerifyCPUSupport() )
    {
        printf("CPU supported for SSE/SSE2\n");
    }

    if ( SSE4::XMVerifySSE4Support() )
    {
        printf("SSE4 supported\n");
    }

    return 0;
}