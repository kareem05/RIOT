/*
 * Copyright (C) 2015 Kaspar Schleiser <kaspar@schleiser.de>
 *
 * This file is subject to the terms and conditions of the GNU Lesser General
 * Public License v2.1. See the file LICENSE in the top level directory for
 * more details.
 */

/**
 * @defgroup    dev_eth_tap     Ethernet driver for TAP interfaces
 * @ingroup     native_cpu
 * @brief       Low-level ethernet driver for native tap interfaces
 * @{
 *
 * @file
 * @brief       Definitions for @ref net_dev_eth driver for host system's
 *              TAP interfaces
 *
 * @author      Kaspar Schleiser <kaspar@schleiser.de>
 */
#ifndef DEV_ETH_TAP_H
#define DEV_ETH_TAP_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "net/dev_eth.h"

#include "net/if.h"

/**
 * @brief tap interface state
 */
typedef struct dev_eth_tap {
    dev_eth_t ethdev;                   /**< dev_eth internal member */
    char tap_name[IFNAMSIZ];            /**< host dev file name */
    int tap_fd;                         /**< host file descriptor for the TAP */
    uint8_t addr[ETHERNET_ADDR_LEN];    /**< The MAC address of the TAP */
    uint8_t promiscous;                 /**< Flag for promiscous mode */
} dev_eth_tap_t;

/**
 * @brief global device struct. driver only supports one tap device as of now.
 */
extern dev_eth_tap_t dev_eth_tap;

/**
 * @brief Setup dev_eth_tap_t structure.
 *
 * @param dev  the preallocated dev_eth_tap device handle to setup
 * @param name Name of the host system's tap inteface to bind to.
 */
void dev_eth_tap_setup(dev_eth_tap_t *dev, const char *name);

/**
 * @brief Cleanup dev_eth_tap_t structure.
 *
 * @param dev  the dev_eth_tap device handle to cleanup
 */
void dev_eth_tap_cleanup(dev_eth_tap_t *dev);

#ifdef __cplusplus
}
#endif
/** @} */
#endif /* DEV_ETH_TAP_H */
