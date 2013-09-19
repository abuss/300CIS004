#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <boost/regex.hpp>
#include "guess_vista_html.h"


// Vista usando CGI/HTML
void guessVistaHTML::forma_captura()
{
  // Punto pt;
  std::cout << "Content-type: text/html" << std::endl << std::endl;
  std::cout << "<html><body><form method='post'>\n";
  std::cout << "X:<input name='x'> Y:<input name='y'> Z:<input name='z'>";
  std::cout << "<input type='submit'>";
  std::cout << "<html><body><form>\n";
}

Punto guessVistaHTML::leer()
{
  std::string datos;
  std::cin >> datos;

  boost::regex ws_re("&");
  boost::regex assing_re("([a-z]+)=(.*)");

  Punto pt;

  auto it = boost::sregex_token_iterator(datos.begin(), datos.end(), ws_re, -1);
  boost::cmatch m;
  std::string substr = *it;
  if(boost::regex_match(substr.c_str(), m, assing_re)) {
    pt.x = atoi(m[2].str().c_str());
  }
  ++it;
  substr = *it;
  if(boost::regex_match(substr.c_str(), m, assing_re)) {
    pt.y = atoi(m[2].str().c_str());
  }
  ++it;
  substr = *it;
  if(boost::regex_match(substr.c_str(), m, assing_re)) {
    pt.z = atoi(m[2].str().c_str());
  }

  return pt;
}
