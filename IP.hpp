#pragma once

#include <string>

class IP {
private:
  std::string address_;
  std::string cidr_mask_;
public:
  IP(const std::string &address);
  IP(const std::string &address, const std::string &cidr_mask);
  std::string get() const;
  const std::string &get_address() const;
  const std::string &get_cidr_mask() const;
  /* Operator overloadings */
  bool operator==(const IP &other) const;
};

std::ostream &operator<<(std::ostream &os, const IP &ip);
