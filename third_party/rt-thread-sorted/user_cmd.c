/************************************************
 * @file user_cmd.c
 * @author Trisuborn (ttowfive@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-11-09
 * 
 * @copyright Copyright (c) 2020
 * 
 ************************************************/
#include "stm32f10x_conf.h"
#include <rtthread.h>
#include <rthw.h>

/************************************************
 * @brief cmd for msh
 ************************************************/

static void reboot(int argc, char **args)
{
    rt_hw_cpu_reset();
}
MSH_CMD_EXPORT(reboot, reboot cpu);

static int clear(void)
{
    rt_kprintf("\x1b[2J\x1b[H");
    return 0;
}
MSH_CMD_EXPORT(clear,clear the terminal screen);
