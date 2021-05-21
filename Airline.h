#pragma once
#include <iostream>

class Airline{
private:
  std::string *name;
public:
  Airline();
  Airline(std::string n);
  std::string getName() const;
  void setName(std::string n) const;
  ~Airline();
  friend std::ostream& operator<<(std::ostream& os, const Airline& a1);
};