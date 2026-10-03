/* MediaTek additions to libnetutils that the stock thermal daemon links
 * against. They throttle the modem and Wi-Fi transmit queues; without them
 * the daemon cannot start at all. */

int ifc_set_throttle(const char *ifname, int rx_rate_kbps, int tx_rate_kbps) {
    (void)ifname; (void)rx_rate_kbps; (void)tx_rate_kbps;
    return 0;
}

int ifc_set_txq_state(const char *ifname, int state) {
    (void)ifname; (void)state;
    return 0;
}
