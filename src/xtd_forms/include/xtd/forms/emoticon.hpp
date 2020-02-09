#pragma once
#include "component.hpp"
#include <xtd/static.hpp>
#include <string>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class emoticon : public component {
    public:
      static const emoticon empty();
      
      emoticon(const std::string& name, std::initializer_list<char32_t> codepoints) : name_(name), codepoints_(codepoints) {}
      
      emoticon(const std::string& name, const std::vector<char32_t>& codepoints) : name_(name), codepoints_(codepoints) {}
      
      emoticon(const std::string& name, char32_t codepoint) : name_(name), codepoints_({codepoint}) {}
      
      emoticon(const std::string& name, std::initializer_list<char> codepoints) : name_(name) {
        for(auto codepoint : codepoints)
          codepoints_.push_back(static_cast<char32_t>(codepoint));
      }
      
      emoticon(const std::string& name, const std::vector<char>& codepoints) : name_(name) {
        for(auto codepoint : codepoints)
          codepoints_.push_back(static_cast<char32_t>(codepoint));
      }
      
      emoticon(const std::string& name, char codepoint) : name_(name), codepoints_({static_cast<char32_t>(codepoint)}) {}
      
      emoticon(const std::string& name, std::initializer_list<char16_t> codepoints) : name_(name) {
        for(auto codepoint : codepoints)
          codepoints_.push_back(static_cast<char32_t>(codepoint));
      }
      
      emoticon(const std::string& name, const std::vector<char16_t>& codepoints) : name_(name) {
        for(auto codepoint : codepoints)
          codepoints_.push_back(static_cast<char32_t>(codepoint));
      }
      
      emoticon(const std::string& name, char16_t codepoint) : name_(name), codepoints_({static_cast<char32_t>(codepoint)}) {}
      
      emoticon(const std::string& name, std::initializer_list<int32_t> codepoints) : name_(name) {
        for(auto codepoint : codepoints)
          codepoints_.push_back(static_cast<char32_t>(codepoint));
      }
      
      emoticon(const std::string& name, const std::vector<int32_t>& codepoints) : name_(name) {
        for(auto codepoint : codepoints)
          codepoints_.push_back(static_cast<char32_t>(codepoint));
      }
      
      emoticon(const std::string& name, int32_t codepoint) : name_(name), codepoints_({static_cast<char32_t>(codepoint)}) {}
      
      /// @cond
      emoticon() = default;
      emoticon(const emoticon&) = default;
      emoticon& operator=(const emoticon&) = default;
      bool operator==(const emoticon& value) {return name_ == value.name_ && codepoints_ == value.codepoints_;}
      bool operator!=(const emoticon& value) {return !operator==(value);}
      friend std::ostream& operator<<(std::ostream& os, const xtd::forms::emoticon& emoticon) noexcept {
        return os << emoticon.to_string();
      }
      /// @endcond
      
      const std::string& name() const {return name_;}
      
      const std::vector<char32_t>& codepoints() const {return codepoints_;}
      
      std::string to_string() const {
        std::string result;
        for (auto codepoint : codepoints_) {
          if (codepoint < 0x80) {
            result.push_back(static_cast<char>(codepoint));
          } else  if (codepoint < 0x800) {
            result.push_back(static_cast<char>((codepoint >> 6) | 0xc0));
            result.push_back(static_cast<char>((codepoint & 0x3f) | 0x80));
          } else if (codepoint < 0x10000) {
            result.push_back(static_cast<char>((codepoint >> 12) | 0xe0));
            result.push_back(static_cast<char>(((codepoint >> 6) & 0x3f) | 0x80));
            result.push_back(static_cast<char>((codepoint & 0x3f) | 0x80));
          } else {
            result.push_back(static_cast<char>((codepoint >> 18) | 0xf0));
            result.push_back(static_cast<char>(((codepoint >> 12) & 0x3f) | 0x80));
            result.push_back(static_cast<char>(((codepoint >> 6) & 0x3f) | 0x80));
            result.push_back(static_cast<char>((codepoint & 0x3f) | 0x80));
          }
        }
        return result;
      }
      
    private:
      std::string name_;
      std::vector<char32_t> codepoints_;
    };
  }
}
