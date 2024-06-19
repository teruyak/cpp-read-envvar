#include <cstdlib>
#include <iostream>
#include <optional>
#include <string>
#include <sstream>

std::string getEnvVarAsString(const char* env_var_name)
{
  const char* env_var_value = std::getenv(env_var_name);
  if(env_var_value == nullptr)
  {
    throw std::runtime_error("env var not found: " + std::string(env_var_name));
  }

  return std::string(env_var_value);
}

int getEnvVarAsInt(const char *env_var_name)
{
  std::string env_var_value = getEnvVarAsString(env_var_name);

  try
  {
    return std::stoi(env_var_value);
  }
  catch(const std::exception& e)
  {
    throw std::runtime_error("env var couldn't parse as int: " + std::string(env_var_name));
  }
}

class Params
{
  public:
    std::string home;
    int lucky_number;
    std::string toString();
};

std::string Params::toString()
{
  std::stringstream ss;
  ss << "home: " << home << std::endl;
  ss << "lucky_number: " << lucky_number;
  return ss.str();
}

int main()
{
  Params params;
  params.home = getEnvVarAsString("HOME");
  params.lucky_number = getEnvVarAsInt("lucky_number");
  std::cout << params.toString() << std::endl;

  return EXIT_SUCCESS;
}
