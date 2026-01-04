#pragma once

#include <string>

class MAC {
private:
  std::string address_;
public:
  MAC(const std::string &address);
  const std::string& get() const;
  /* Operator overloadings */
  bool operator==(const MAC &other) const;
};

std::ostream &operator<<(std::ostream &os, const MAC &mac);
