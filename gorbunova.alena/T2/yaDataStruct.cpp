#include <iomanip>
#include "delimiter.hpp"
#include "yaDataStruct.hpp"
#include "iofmtguard.hpp"

std::istream &gorbunova::operator>>(std::istream &in, YaDataStruct &data)
{
  std::istream::sentry guard(in);
  if(!guard)
  {
    return in;
  }
  YaDataStruct input;
  {
    std::string key = "";
    in >> Delimiter{'('};
    for(size_t i = 0; i < 3; ++i)
    {
      in >> Delimiter{':'} >> key;
      if (key == "key1")
      {
        in >> Ratio{input.key1};
      }
      else if (key == "key2")
      {
        in >> Ull{input.key2};
      }
      else if (key == "key3")
      {
        in >> Str{input.key3};
      }
    }
    in >> Delimiter{':'} >> Delimiter{')'};
  }
  if (in)
  {
    data = input;
  }
  return in;
}

std::ostream &gorbunova::operator<<(std::ostream &out, const YaDataStruct &data)
{
  std::ostream::sentry sentry(out);
  if (!sentry)
  {
    return out;
  }
  iofmtguard fmtguard(out);
  out << ":key1 " << "(:N " << data.key1.first << ":D " << data.key1.second << ":)";
  out << ":key2 \"" << data.key2 << "\":)";
  out << ":key3 " << data.key3 << ":)";
  return out;
}

bool gorbunova::operator<(const YaDataStruct &lhs, const YaDataStruct &rhs)
{
  if (lhs.key1 != rhs.key1)
  {
    return lhs.key1.first < rhs.key1.first ||
           (lhs.key1.first == rhs.key1.first && lhs.key1.second < rhs.key1.second);
  }
  else if (lhs.key2 != rhs.key2)
  {
    return lhs.key2 < rhs.key2;
  }
  else
  {
    return lhs.key3.length() < rhs.key3.length();
  }
}

std::istream &gorbunova::operator>>(std::istream &in, Ull &&dest)
{
  std::istream::sentry guard(in);
  if (!guard)
  {
    return in;
  }
  in >> dest.ref >> Delimiter{'u'} >> Delimiter{'l'} >> Delimiter{'l'};
  if (!in)
  {
    in.setstate(std::ios::failbit);
  }
  return in;
}
