#include <iostream>

#include "IP.hpp"

int main(void) {
  IP my_laptop_ip("192.168.1.100", "24");
  IP my_vpn_ip("10.8.0.3");

  std::cout << "my laptop ip : " << my_laptop_ip
            << " and my vpn ip : " << my_vpn_ip << "\n";
  
  return 0;
}
