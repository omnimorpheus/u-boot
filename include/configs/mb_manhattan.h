/*
 * Copyright (C) 2010 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Based on davinci_dvevm.h. Original Copyrights follow:
 *
 * Copyright (C) 2007 Sergey Kubushyn <ksi@koi8.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/*
 * Board
 */
#define CONFIG_DRIVER_TI_EMAC

#define	CONFIG_SYS_USE_NAND	1

/*
 * SoC Configuration
 */
#define CONFIG_MACH_DAVINCI_MANHATTAN
#define CONFIG_ARM926EJS		/* arm926ejs CPU core */
#define CONFIG_SOC_DA8XX		/* TI DA8xx SoC */
#define CONFIG_SOC_DA850		/* TI DA850 SoC */
#define CONFIG_SYS_EXCEPTION_VECTORS_HIGH
#define CONFIG_SYS_CLK_FREQ		clk_get(DAVINCI_ARM_CLKID)
#define CONFIG_SYS_OSCIN_FREQ		24000000
#define CONFIG_SYS_TIMERBASE		DAVINCI_TIMER0_BASE
#define CONFIG_SYS_HZ_CLOCK		clk_get(DAVINCI_AUXCLK_CLKID)
#define CONFIG_SYS_HZ			1000
#define CONFIG_SKIP_LOWLEVEL_INIT
#define CONFIG_BOARD_EARLY_INIT_F
#define CONFIG_SYS_TEXT_BASE		0xc1080000
#define CONFIG_AIS_CONFIG_FILE		"board/$(BOARDDIR)/manhattan-ais-nand.cfg"

/*
 * Memory Info
 */
#define CONFIG_SYS_MALLOC_LEN	(0x10000 + 1*1024*1024) /* malloc() len */
#define PHYS_SDRAM_1		DAVINCI_DDR_EMIF_DATA_BASE /* DDR Start */
#define PHYS_SDRAM_1_SIZE	(128 << 20) /* SDRAM size 128MB */
#define CONFIG_MAX_RAM_BANK_SIZE (512 << 20) /* max size from SPRS586*/

/* memtest start addr */
#define CONFIG_SYS_MEMTEST_START	(PHYS_SDRAM_1 + 0x2000000)

/* memtest will be run on 16MB */
#define CONFIG_SYS_MEMTEST_END 	(PHYS_SDRAM_1 + 0x2000000 + 16*1024*1024)

#define CONFIG_NR_DRAM_BANKS	1 /* we have 1 bank of DRAM */

/* Spl */
#define CONFIG_SPL
#define CONFIG_SPL_FRAMEWORK
#define CONFIG_SPL_BOARD_INIT
#define CONFIG_SPL_NAND_SUPPORT
#define CONFIG_SPL_NAND_BASE
#define CONFIG_SPL_NAND_DRIVERS
#define CONFIG_SPL_NAND_ECC
#define CONFIG_SPL_NAND_SIMPLE
#define CONFIG_SPL_LIBGENERIC_SUPPORT	/* for udelay and __div64_32 for NAND */
#define CONFIG_SPL_SERIAL_SUPPORT
#define CONFIG_SPL_LDSCRIPT		"board/$(BOARDDIR)/u-boot-spl-hawk.lds"
#define CONFIG_SPL_TEXT_BASE		0xc1080000
#define CONFIG_SPL_STACK		CONFIG_SYS_INIT_SP_ADDR


#define CONFIG_SYS_DA850_SYSCFG_SUSPSRC (	\
	DAVINCI_SYSCFG_SUSPSRC_TIMER0 |		\
	DAVINCI_SYSCFG_SUSPSRC_SPI1 |		\
	DAVINCI_SYSCFG_SUSPSRC_UART1 |		\
	DAVINCI_SYSCFG_SUSPSRC_EMAC |		\
	DAVINCI_SYSCFG_SUSPSRC_I2C)

/*
 * Serial Driver info
 */
#define CONFIG_SYS_NS16550
#define CONFIG_SYS_NS16550_SERIAL
#define CONFIG_SYS_NS16550_REG_SIZE	-4	/* NS16550 register size */
#define CONFIG_SYS_NS16550_COM1	DAVINCI_UART1_BASE /* Base address of UART1 */
#define CONFIG_SYS_NS16550_CLK	clk_get(DAVINCI_UART1_CLKID)
#define CONFIG_CONS_INDEX	1		/* use UART0 for console */
#define CONFIG_BAUDRATE		115200		/* Default baud rate */

/*
 * Flash & Environment
 */
#ifdef CONFIG_SYS_USE_NAND
#undef CONFIG_ENV_IS_IN_FLASH
#define CONFIG_NAND_DAVINCI
#define CONFIG_SYS_NAND_ONFI_DETECTION
#define CONFIG_SYS_NO_FLASH
#define CONFIG_ENV_IS_IN_NAND		/* U-Boot env in NAND Flash  */
#define CONFIG_ENV_OFFSET		0x0 /* Block 0--not used by bootcode */
#define CONFIG_ENV_SIZE			(256 << 12)
#define	CONFIG_SYS_NAND_USE_FLASH_BBT
#define CONFIG_SYS_NAND_ECC_BCH
#define	CONFIG_SYS_NAND_PAGE_4K
#define CONFIG_SYS_NAND_CS		3
#define CONFIG_SYS_NAND_BASE		DAVINCI_ASYNC_EMIF_DATA_CE3_BASE
#define CONFIG_SYS_CLE_MASK		0x10
#define CONFIG_SYS_ALE_MASK		0x8
#undef CONFIG_SYS_NAND_HW_ECC
#define CONFIG_SYS_MAX_NAND_DEVICE	1 /* Max number of NAND devices */

#define CONFIG_SYS_NAND_PAGE_SIZE	(1 << 12)
#define CONFIG_SYS_NAND_BLOCK_SIZE	(256 << 12)
#define CONFIG_SYS_NAND_U_BOOT_OFFS	0x600000
#define CONFIG_SYS_NAND_U_BOOT_DST	0xc1080000
#define CONFIG_SYS_NAND_U_BOOT_START	CONFIG_SYS_NAND_U_BOOT_DST
#define CONFIG_SYS_NAND_U_BOOT_RELOC_SP	(CONFIG_SYS_NAND_U_BOOT_DST - \
					CONFIG_SYS_NAND_U_BOOT_SIZE - \
					CONFIG_SYS_MALLOC_LEN -       \
					GENERATED_GBL_DATA_SIZE)
#define CONFIG_SYS_NAND_ECCPOS		{				\
		48, 49, 50, 51, 52, 53, 54, 55, 56, 57,     \
		58, 59, 60, 61, 62, 63,	64, 65, 66, 67,     \
		68, 69, 70, 71, 72, 73, 74, 75, 76, 77,     \
		78, 79,	80, 81, 82, 83,	84, 85, 86, 87,     \
		88, 89, 90, 91, 92, 93,	94, 95, 96, 97,     \
		98, 99, 100, 101, 102, 103, 104, 105, 106, 107,    \
		108, 109, 110, 111, 112, 113, 114, 115, 116, 117,  \
		118, 119, 120, 121, 122, 123, 124, 125, 126, 127}  \
		
#define CONFIG_SYS_NAND_PAGE_COUNT	256
#define CONFIG_SYS_NAND_BAD_BLOCK_POS	0
#define CONFIG_SYS_NAND_ECCSIZE		512
#define CONFIG_SYS_NAND_ECCBYTES	10
#define CONFIG_SYS_NAND_OOBSIZE		224
#endif

/*
 * Network & Ethernet Configuration
 */
#ifdef CONFIG_DRIVER_TI_EMAC
#define CONFIG_MII
#define CONFIG_BOOTP_DEFAULT
#define CONFIG_BOOTP_DNS
#define CONFIG_BOOTP_DNS2
#define CONFIG_BOOTP_SEND_HOSTNAME
#define CONFIG_NET_RETRY_COUNT	10
#endif


/*
 * U-Boot general configuration
 */
#define CONFIG_MISC_INIT_R
#define CONFIG_BOARD_EARLY_INIT_F
#define CONFIG_BOOTFILE		"boot/uImage" /* Boot file name */
#define CONFIG_SYS_PROMPT	"Manhattan > " /* Command Prompt */
#define CONFIG_SYS_CBSIZE	1024 /* Console I/O Buffer Size	*/
#define CONFIG_SYS_PBSIZE	(CONFIG_SYS_CBSIZE+sizeof(CONFIG_SYS_PROMPT)+16)
#define CONFIG_SYS_MAXARGS	26 /* max number of command args */
#define CONFIG_SYS_BARGSIZE	CONFIG_SYS_CBSIZE /* Boot Args Buffer Size */
#define CONFIG_SYS_LOAD_ADDR	(PHYS_SDRAM_1 + 0x700000)
#define CONFIG_VERSION_VARIABLE
#define CONFIG_AUTO_COMPLETE
#define CONFIG_SYS_HUSH_PARSER
#define CONFIG_CMDLINE_EDITING
#define CONFIG_SYS_LONGHELP
#define CONFIG_CRC32_VERIFY
#define CONFIG_MX_CYCLIC

/*
 * Linux Information
 */
#define LINUX_BOOT_PARAM_ADDR	(PHYS_SDRAM_1 + 0x100)
#define CONFIG_HWCONFIG		/* enable hwconfig */
#define CONFIG_CMDLINE_TAG
#define CONFIG_REVISION_TAG
#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_BOOTDELAY	3
#define CONFIG_EXTRA_ENV_SETTINGS	"setbootargs=setenv bootargs console=ttyS1,115200n8 noinitrd ip=off " \
    "mem=128M@0xC0000000 rootdelay=1 rw ubi.mtd=${current_root_mtd},4096 rootfstype=ubifs root=ubi0:filesystem" \
    " init=/linuxrc eth=${macaddr}\0" \
    "current_root_mtd=4\0" \
    "vid=23C1\0" \

#define CONFIG_BOOTCOMMAND "run setbootargs; nand read 0xC0000000 0x1000000 0x300000;bootm 0xC0000000"

/*
 * U-Boot commands
 */
#include <config_cmd_default.h>
#define CONFIG_CMD_ENV
#define CONFIG_CMD_ASKENV
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_DIAG
#define CONFIG_CMD_MII
#define CONFIG_CMD_PING
#define CONFIG_CMD_SAVES
#define CONFIG_CMD_MEMORY

#ifdef CONFIG_CMD_BDI
#define CONFIG_CLOCKS
#endif

#ifndef CONFIG_DRIVER_TI_EMAC
#undef CONFIG_CMD_NET
#undef CONFIG_CMD_DHCP
#undef CONFIG_CMD_MII
#undef CONFIG_CMD_PING
#endif

#ifdef CONFIG_SYS_USE_NAND
#undef CONFIG_CMD_FLASH
#undef CONFIG_CMD_IMLS
#define CONFIG_CMD_NAND

#define CONFIG_CMD_MTDPARTS
#define CONFIG_MTD_DEVICE
#define CONFIG_MTD_PARTITIONS
#define CONFIG_LZO
#define CONFIG_RBTREE
#define CONFIG_CMD_UBI
#define CONFIG_CMD_UBIFS
#endif


/* additions for new relocation code, must added to all boards */
#define CONFIG_SYS_SDRAM_BASE		0xc0000000

#define CONFIG_SYS_INIT_SP_ADDR		(CONFIG_SYS_SDRAM_BASE + 0x1000 - /* Fix this */ \
					GENERATED_GBL_DATA_SIZE)
#endif /* __CONFIG_H */