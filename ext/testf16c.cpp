#include <stdio.h>

#include "DirectXMathF16C.h"

using namespace DirectX;

int main()
{
    if ( XMVerifyCPUSupport() )
    {
        printf("CPU supported for SSE/SSE2\n");
    }

    if ( F16C::XMVerifyF16CSupport() )
    {
        printf("F16C supported\n");
    }

    return 0;
}