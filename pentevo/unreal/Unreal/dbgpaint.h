#pragma once

struct MENUITEM
{
   const char *text;
   enum FLAGS { DISABLED = 1, LEFT = 2, RIGHT = 4, CENTER = 8 } flags;
};

struct MENUDEF
{
   MENUITEM *items;
   unsigned n_items;
   const char *title;
   unsigned pos;
};

extern u8 txtscr[80*30*2];
extern char str[0x80];
extern unsigned nfr;

void filledframe(unsigned x, unsigned y, unsigned dx, unsigned dy, u8 color = FFRAME_INSIDE);
void fillattr(unsigned x, unsigned y, unsigned dx, u8 color = FFRAME_INSIDE);
void tprint(unsigned x, unsigned y, const char *str, u8 attr);
void tprint_fg(unsigned x, unsigned y, const char *str, u8 attr);
unsigned inputhex(unsigned x, unsigned y, unsigned sz, bool hex);
unsigned input2(unsigned x, unsigned y, unsigned val);
unsigned input4(unsigned x, unsigned y, unsigned val);
void debugflip();
char handle_menu(MENUDEF *menu);
void frame(unsigned x, unsigned y, unsigned dx, unsigned dy, u8 attr);
