
#include "main.h"
#include "ft6236.h"
#include "lcd_st7789.h"

int main()
{
//    ctp_ft6236_init();
    lcd_st7789_init();
    while (1) {
//        ctp_ft6236_scan();
        DELAY(100);
    }
}
