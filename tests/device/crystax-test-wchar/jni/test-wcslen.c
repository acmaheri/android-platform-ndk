#include <stdio.h>
#include <wchar.h>
#include <assert.h>

int main()
{
    printf("1..1 - wcslen_c\n");

    wchar_t *s;
    size_t len;

    s = L"abcdefghijkl";
    len = wcslen(s);
    printf("len: %lu\n", (unsigned long)len);
    assert(len == 12);

    printf("ok 1 - wcslen_c\n");
    return (0);
}
