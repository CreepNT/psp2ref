#ifndef __REF_ERNIE_H__
#define __REF_ERNIE_H__

#include "ref_types.h"

// basics
#define ERNIE_TX_CMD_LO	0
#define ERNIE_TX_CMD_HI	1
#define ERNIE_TX_LENGTH	2
#define ERNIE_TX_DATA(i)	(3 + (i))
#define ERNIE_RX_STATUS_LO	0
#define ERNIE_RX_STATUS_HI	1
#define ERNIE_RX_LENGTH	2
#define ERNIE_RX_RESULT	3
#define ERNIE_RX_DATA(i)	(4 + (i))

#define ERNIE_TX_SIZE(data_size) (ERNIE_TX_DATA(0) + 1 + data_size)
#define ERNIE_RX_SIZE(data_size) (ERNIE_RX_DATA(0) + 1 + data_size)

#define ERNIE_DEFAULT_PACKET_SIZE 0x20

typedef struct ernie_comms_t {
    uint8_t tx[ERNIE_DEFAULT_PACKET_SIZE];
    uint8_t rx[ERNIE_DEFAULT_PACKET_SIZE];
} ernie_comms_t;

// ernie commands & their args
enum ERNIE_COMMANDS {
    ERNIE_CMD_GET_HWINFO = 5,
    ERNIE_CMD_SET_KERMIT_BUFSZ = 0x80,
    ERNIE_CMD_GET_SCRATCHPAD = 0x90,
    ERNIE_CMD_SET_SCRATCHPAD = 0x91,
    ERNIE_CMD_3AUTH_DEFAULT = 0xA0,
    ERNIE_CMD_CTRL_HOVD = 0xB2,
    ERNIE_CMD_SET_UART0 = 0x190,
    ERNIE_CMD_GET_KERMITJIG_SHBUF = 0x2083,
    ERNIE_CMD_SET_KERMITJIG_SHBUF = 0x2085,
};

enum ERNIE_UART0_SWITCH_MODES {
    ERNIE_UART0_MODE_ERNIE,
    ERNIE_UART0_MODE_KERMIT,
    ERNIE_UART0_MODE_OFF = 0xFF,
};

#define ERNIE_3AUTH_SIZE 0x28

#endif