#include "IP.hpp"

#include <stdexcept>
#include <string>
#include <regex>

IP::IP(const std::string &address, const std::string &cidr_mask) : address_(address), cidr_mask_(cidr_mask) {
  if (address.empty()) {
    throw std::runtime_error("Address cannot be empty");
  }

  if (cidr_mask.empty()) {
    throw std::runtime_error("Mask cannot be empty");
  }

  
  static const std::regex ip_pattern(R"(^(25[0-5]|2[0-4][0-9]|1?[0-9]{1,2})(\.(25[0-5]|2[0-4][0-9]|1?[0-9]{1,2})){3}$)");
  static const std::regex cidr_pattern(R"(^(3[0-2]|[1-2]?[0-9])$)");
  if (!std::regex_match(address, ip_pattern)) {
    throw std::runtime_error(address + " is an invalid address");
  }
    
  if (!std::regex_match(cidr_mask, cidr_pattern)) {
    throw std::runtime_error(cidr_mask + " is an invalid mask");
  }
};

IP::IP(const std::string &address) : IP(address, "32") {}

std::string IP::get() const { return address_ + "/" + cidr_mask_; }

const std::string &IP::get_address() const { return address_; }

const std::string &IP::get_cidr_mask() const { return cidr_mask_; }

bool IP::operator==(const IP &other) const {
  return address_ == other.address_ && cidr_mask_ == other.cidr_mask_;
}

std::ostream &operator<<(std::ostream &os, const IP &ip) {
  os << ip.get();
  return os;
}

