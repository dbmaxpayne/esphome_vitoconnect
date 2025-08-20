#pragma once

#include "esphome/components/socket/socket.h"
#include "vitoconnect_optolink.h"

namespace esphome {
namespace vitoconnect {
class OptolinkServer {
  public:
  private:
    struct Client {
        Client(std::unique_ptr<esphome::socket::Socket> socket, std::string identifier, size_t position);

        std::unique_ptr<esphome::socket::Socket> socket{nullptr};
        std::string identifier{};
        bool disconnected{false};
        size_t position{0};
    };
};
}  // namespace vitoconnect
}  // namespace esphome
