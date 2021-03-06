/*
 * Copyright 2019 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef KEY_BLOB_H
#define KEY_BLOB_H

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <stdbool.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/types.h>

typedef struct {
	uint32_t key_len;
	uint32_t key_color;
	uint32_t key_cover;
	uint32_t blob_len;
}kb_parameter_t;

typedef struct {
	uint32_t key_len;
	uint32_t key_color;
	uint32_t key_cover;
	uint32_t blob_len;
	uint8_t buffer[16];
	uint8_t returned;
}kb_operation_t;

typedef struct {
	uint8_t *key_addr;
	uint8_t *blob_addr;
}kb_addr_t;

#define KB_IOCTL_ENCAP			_IOWR('K', 0, kb_parameter_t)
#define KB_IOCTL_DECAP			_IOWR('K', 1, kb_parameter_t)
#define KB_IOCTL_SEND_VRT_ADDR	_IOR('K', 2, kb_addr_t)

#endif /* KEY_BLOB_H */
