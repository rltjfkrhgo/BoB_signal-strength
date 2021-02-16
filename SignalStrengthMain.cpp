// SignalStrengthMain.cpp

#include <pcap.h>
#include <stdio.h>

void usage()
{
    printf("syntax: signal-strength <interface> <mac>\n");
    printf("sample: signal-strength mon0 00:11:22:33:44:55\n");
}

int main(int argc, char* argv[])
{
    if (argc != 3) {
        usage();
        return -1;
    }

    char* dev = argv[1];
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    //pcap_t* handle = pcap_open_offline(dev, errbuf);
    if (handle == nullptr) {
        fprintf(stderr, "pcap_open_live(%s) return nullptr - %s\n", dev, errbuf);
        return -1;
    }

    while (true)
    {
        struct pcap_pkthdr* header;
        const u_char* packet;
        int res = pcap_next_ex(handle, &header, &packet);  // 패킷 수신
        if (res == 0) continue;
        if (res == -1 || res == -2) {
            printf("pcap_next_ex return %d(%s)\n", res, pcap_geterr(handle));
            break;
        }
    }

    pcap_close(handle);

    return 0;
}