#include <assert.h>

int main(void)
{
    assert(__linux == 1);
    assert(__ELF__ == 1);
    assert(__STDC_EMBD_NOT_FOUND__ == 0);
    assert(__STDC_EMBED_EMPTY__ == 2);
    assert(__STDC_VERSION__ == 202311L);
}
