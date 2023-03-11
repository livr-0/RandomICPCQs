#include <iostream>

using namespace std;

int main() {
    int packet_len, message_len;
    cin >> packet_len >> message_len;

    int digits;
    for (digits = 1; digits < (packet_len - 3) / 2; digits++) {
        int remaining = message_len;
        int overhead = digits + 3;
        int packets = 9;
        for (; overhead <= 2 * digits + 2; overhead++, packets *= 10) {
            remaining -= packets * (packet_len - overhead);
        }
        if (remaining <= 0) {
            break;
        }
    }

    int total_packets = 0;
    int remaining = message_len;
    int overhead = digits + 3;
    int packets = 9;
    for (; overhead <= 2 * digits + 2; overhead++, packets *= 10) {
        int content_len = packet_len - overhead;
        int packets_req = (remaining + content_len - 1) / content_len;
        if (packets_req > packets) {
            remaining -= packets * content_len;
            total_packets += packets;
        } else {
            remaining -= packets_req * content_len;
            total_packets += packets_req;
        }
        if (remaining <= 0) {
            cout << total_packets << "\n";
            return 0;
        }
    }

    cout << "-1\n";
    return 0;
}
