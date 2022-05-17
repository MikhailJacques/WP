// AUTHOR:		Mikhail Jacques
// PROJECT:		Fun
// DOCUMENT:	None
// DESCRIPTION: This file defines message buffer that stores all incoming messages in raw data format

#pragma once

const unsigned short MSG_BUFF_LEN = (1024);

typedef struct msg_buff_struct
{
	unsigned char payload_bptr[MSG_BUFF_LEN];
} MSG_BUFF_STRUCT;

typedef struct msg_struct
{
    unsigned short len;
    unsigned char payload_bptr[MSG_BUFF_LEN];

} MSG_STRUCT;
