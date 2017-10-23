/*
 * Diamond inheritance
 *
 *     |Unit|
 *    /      \
 *   Elf    Archer
 *    \      /
 *    ElfArcher
 */

#define unsigned int unitid;

struct Unit {
    unitid id;
};


struct Elf: virtual Unit {};

struct Arche: virtual Unit {};

struct ElfArcher: Elf, Archer {};
