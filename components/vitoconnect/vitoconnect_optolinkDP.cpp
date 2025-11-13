/* VitoWiFi

Copyright 2019 Bert Melis

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/

#include "vitoconnect_optolinkDP.h"
#include "esphome/core/log.h"

namespace esphome {
namespace vitoconnect {

OptolinkDP::OptolinkDP(uint16_t address, uint8_t length, bool write, uint8_t* value, void* arg) :
  address(address),
  length(length),
  write(write),
  data(nullptr),
  arg(arg) {
    if (write) {
      ESP_LOGD("Test", "Test6: %02D", *value);
      data = new uint8_t[length];
      memcpy(data, value, length);
      ESP_LOGD("Test", "Test7: %02D", *data);
    }
  }

OptolinkDP::OptolinkDP() :
  address(0),
  length(0),
  write(false),
  data(nullptr),
  arg(nullptr) {}

OptolinkDP::OptolinkDP(const OptolinkDP& obj) {
  address = obj.address;
  length = obj.length;
  write = obj.write;
  data = nullptr;
  arg = obj.arg;
  if (write) {
    ESP_LOGD("Test", "Test8: %02D", *obj.data);
    data = new uint8_t[length];
    memcpy(data, obj.data, length);
    ESP_LOGD("Test", "Test9: %02D", *data);
  }
}

OptolinkDP::~OptolinkDP() {
  if (data)
  {
      ESP_LOGD("Test", "Test10: %02X", *data);
      //delete[] data;
  }
}

}  // namespace vitoconnect
}  // namespace esphome
