#include "MAC.hpp"

#include <ostream>
#include <regex>
#include <stdexcept>

MAC::MAC(const std::string &address) : address_(address) {
  if (address.empty()) {
    throw std::runtime_error("Address cannot be empty");
  }
  
  if (address.length() != 17) {
    throw std::runtime_error(address + " is an invalid address (not enough characters)");
  }

  static const std::regex mac_pattern("^([0-9A-Fa-f]{2}:){5}[0-9A-Fa-f]{2}$");
  if (!std::regex_match(address, mac_pattern)) {
    throw std::runtime_error(address + " is an invalid address (syntax error)");
  }
};

const std::string &MAC::get() const {
  return address_;
}

bool MAC::operator==(const MAC &other) const {
  return address_ == other.address_;
}

std::ostream &operator<<(std::ostream &os, const MAC &mac) {
  os << mac.get();
  return os;
}
