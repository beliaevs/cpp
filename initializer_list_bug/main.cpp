#include<iostream>
#include <vector>

class Informer
{
public:
  Informer(int i): d_i(i)
  {
    std::cout << "Informer(" << d_i << ")\n";
  }

  Informer()
  {
    std::cout << "Informer():(" << d_i << ")\n";
  }

  Informer(const Informer& i_other): d_i(i_other.d_i)
  {
    std::cout << "copy Informer(" << d_i << ")\n";
  }

  const Informer& operator = (const Informer& i_rhs)
  {
    std::cout << "Informer(" << d_i << ") = Informer(" << i_rhs.d_i << ")\n";
    d_i = i_rhs.d_i;
    return *this;
  }

  ~Informer()
  {
    std::cout << "~Informer(" << d_i << "), alive = " << d_alive << "\n";
    d_alive = false;
  }

  int get() const
  {
    return d_i;
  }

  bool alive() const
  {
    return d_alive;
  }

private:
  int d_i = 0;
  bool d_alive = true;
};

int main()
{
  std::vector<std::initializer_list<Informer>> v = { {1, 2, 3}, {4, 5}, {6} };

  for (const auto& l : v)
  {
    for (const auto& d : l)
    {
      std::cout << d.get() << "(" << d.alive() << ") ";
    }
    std::cout << "\n";
  }

  return 0;
}