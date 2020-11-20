
#include "main.h"
#include "ft6236.h"

int main()
{
    ctp_ft6236_init();
    while (1) {
        ctp_ft6236_scan();
        DELAY(100);
    }
}
