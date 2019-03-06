/* Assembly:
 * main:
        sub     rsp, 8
        mov     edx, 512
        mov     esi, 13345
        mov     edi, 4660
        call    memmove
        mov     edx, 1024
        mov     esi, 4660
        mov     edi, 13345
        call    memmove
        xor     eax, eax
        add     rsp, 8
        ret
 */

#include <cstdint>
#include <cstring>

struct Copy {
    uintptr_t from_{0};
    uintptr_t to_{0};

    Copy() {}

    inline Copy &from(uintptr_t where) {
        from_ = where;
        return *this;
    }

    inline Copy &to(uintptr_t where) {
        to_ = where;
        return *this;
    }

    inline void perform(size_t count) {
        memmove((void *) to_, (const void *) from_, count);
    }
};

int main() {
    Copy().to(0x1234).from(0x3421).perform(512);
    Copy().from(0x1234).to(0x3421).perform(1024);
}
