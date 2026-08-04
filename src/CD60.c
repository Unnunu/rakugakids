#include "common.h"

void func_8000C28C(HeapChunk *);

#ifdef NON_MATCHING
HeapChunk *heap_alloc(HeapChunk **arg0, s32 size) {
    HeapChunk *a0;
    HeapChunk *current;
    HeapChunk *next;
    HeapChunk *sp20;
    s32 sp1C;

    sp1C = FALSE;
    func_8000C28C(*arg0);
    size = ALIGN_16(size);

    current = &D_80044230;
    next = D_80044230.next;

    while (TRUE) {
        if (next == NULL) {
            if (current != &D_80044230) {
                D_80044268 = (HeapChunk *) ((u32) current->data + current->size);
            }
            break;
        } else {
            current = next;
            next = next->next;

            if ((u32) next - (u32) current - current->size - sizeof(HeapChunk) >= size + sizeof(HeapChunk)) {
                sp20 = next;
                sp1C = TRUE;
                break;
            }
        }
    }

    if (sp1C == TRUE) {
        a0 = (HeapChunk *) ((u32) current + current->size + sizeof(HeapChunk));
    } else {
        a0 = D_80044268 = (HeapChunk *) ALIGN_16(D_80044268);
        D_80044268 = (HeapChunk *) ((u32) D_80044268 + size + sizeof(HeapChunk));
    }

    a0->size = size;
    if (sp1C == TRUE) {
        a0->next = sp20;
    } else {
        a0->next = NULL;
    }
    a0->unk_0C = arg0;
    current->next = a0;
    a0->data = (void *) ((u32) a0 + sizeof(HeapChunk));
    return a0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/CD60/heap_alloc.s")
HeapChunk *heap_alloc(HeapChunk **arg0, s32 arg1);
#endif

void func_8000C28C(HeapChunk *arg0) {
    HeapChunk *current;
    HeapChunk *previous;

    if (arg0 != NULL && (u32) arg0 < 0x90000000 && (u32) arg0 >= 0x80000000) {
        current = &D_80044230;

        while (TRUE) {
            previous = current;
            if (current->next == NULL) {
                break;
            }

            current = current->next;
            if (current == arg0) {
                previous->next = current->next;
                *current->unk_0C = NULL;
                break;
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/CD60/func_8000C2E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CD60/func_8000C370.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CD60/func_8000C3A4.s")
